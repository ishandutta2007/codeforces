#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<n; j++)
                a[i][j] = s[j];
        }
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<n; j++)
                b[i][j] = s[j];
        }

        auto flipR = [&] (int i) {
            for (int j=0; j<n; j++)
                a[i][j] ^= 1;
        };

        auto flipC = [&] (int j) {
            for (int i=0; i<n; i++)
                a[i][j] ^= 1;
        };

        for (int j=0; j<n; j++)
            if (a[0][j] != b[0][j])
                flipC(j);
        bool ok = true;
        for (int i=1; i<n; i++)
            if (a[i] != b[i]) {
                flipR(i);
                if (a[i] != b[i]) {
                    ok = false;
                    break;
                }
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}