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

const int MAX = 1e6;

typedef bitset<2 * MAX + 1> B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i] = abs(a[i]);
        }

        vector<B> rdp(n + 1);
        rdp[n][MAX] = 1;
        for (int i=n-1; i>=0; i--)
            rdp[i] = rdp[i+1] | (rdp[i+1] >> a[i]) | (rdp[i+1] << a[i]);

        bool ok = false;
        B ldp;
        ldp[MAX] = 1;
        for (int i=0; i<n; i++) {
            for (int j=ldp._Find_first(); j<=MAX; j=ldp._Find_next(j))
                if (ldp[j] && -MAX <= a[i] - j + MAX && a[i] - j + MAX <= MAX && rdp[i+1][a[i]-j+2*MAX]) {
                    ok = true;
                    break;
                }
            if (ok)
                break;
            ldp = ldp | (ldp >> a[i]) | (ldp << a[i]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}