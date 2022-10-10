#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(n + 1);
        vector<vector<int>> f(m);
        bool ok = true;
        for (int i=0; i<m; i++) {
            int k;
            cin >> k;
            for (int j=0; j<k; j++) {
                int x;
                cin >> x;
                f[i].push_back(x);
            }
            if (k == 1 && ++cnt[f[i][0]] > (m + 1) / 2)
                ok = false;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i=0; i<m; i++) {
            if (f[i].size() == 1) {
                cout << f[i][0] << " ";
                continue;
            }
            for (int x : f[i])
                if (cnt[x] + 1 <= (m + 1) / 2) {
                    cnt[x]++;
                    cout << x << " ";
                    break;
                }
        }
        cout << "\n";
    }

    return 0;
}