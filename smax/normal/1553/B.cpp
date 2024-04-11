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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        int n = (int) s.size(), m = (int) t.size();

        for (int a=0; a<n; a++)
            for (int b=a; b<n; b++)
                if (2 * b - a + 1 >= m) {
                    int j = 0;
                    bool ok = true;
                    for (int i=a; i<=b; i++, j++)
                        if (s[i] != t[j]) {
                            ok = false;
                            break;
                        }
                    if (!ok)
                        continue;
                    for (int i=b-1; j<m; i--, j++)
                        if (s[i] != t[j]) {
                            ok = false;
                            break;
                        }
                    if (ok) {
                        cout << "YES\n";
                        goto done;
                    }
                }
        cout << "NO\n";
        done:;
    }

    return 0;
}