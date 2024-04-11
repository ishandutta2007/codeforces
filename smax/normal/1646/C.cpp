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

const int MAXF = 14;

long long fact[MAXF];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i=1; i<MAXF; i++)
        fact[i] = fact[i-1] * (i + 1);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        int ret = INT_MAX;
        for (int mask=0; mask<1<<MAXF; mask++) {
            long long cur = 0, ban = 0;
            for (int i=0; i<MAXF; i++)
                if (mask >> i & 1) {
                    cur += fact[i];
                    if ((fact[i] & (fact[i] - 1)) == 0)
                        ban |= fact[i] & -fact[i];
                }
            if (cur <= n && ((n - cur) & ban) == 0)
                ret = min(ret, __builtin_popcount(mask) + __builtin_popcountll(n - cur));
        }
        cout << (ret == INT_MAX ? -1 : ret) << "\n";
    }

    return 0;
}