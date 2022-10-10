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

const int LOG = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> lp(n + 1);
    for (int p=2; p<=n; p++)
        if (lp[p] == 0)
            for (int i=p; i<=n; i+=p)
                lp[i] = p;

    vector<bool> vis(m * LOG + 1);
    vector<int> cnt(LOG);
    for (int i=1; i<LOG; i++)
        for (int j=1; j<=m; j++)
            if (!vis[i*j]) {
                vis[i*j] = true;
                cnt[i]++;
            }

    long long ret = 1;
    for (int x=2; x<=n; x++) {
        int y = x, g = 0;
        while (y > 1) {
            int p = lp[y], e = 0;
            while (y % p == 0) {
                y /= p;
                e++;
            }
            g = gcd(g, e);
        }
        ret += cnt[g];
    }
    cout << ret << "\n";

    return 0;
}