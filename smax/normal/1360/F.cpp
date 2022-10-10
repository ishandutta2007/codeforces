#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

string a[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                string cpy = a[i];
                for (char c='a'; c<='z'; c++) {
                    cpy[j] = c;
                    bool ok = true;
                    for (int k=0; k<n; k++) {
                        int diff = 0;
                        for (int l=0; l<m; l++)
                            diff += (a[k][l] != cpy[l]);
                        if (diff > 1) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        cout << cpy << "\n";
                        goto done;
                    }
                }
            }
        }

        cout << "-1\n";
        done:continue;
    }

    return 0;
}