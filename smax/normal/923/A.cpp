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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int x2;
    cin >> x2;

    int p, n = x2;
    for (int i=2; i*i<=n; i++)
        if (n % i == 0) {
            p = i;
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p = n;

    int ret = INT_MAX;
    for (int x1=x2-p+1; x1<=x2; x1++) {
        n = x1;
        for (int i=2; i*i<=n; i++)
            if (n % i == 0) {
                ret = min(ret, x1 - i + 1);
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1 && n < x1)
            ret = min(ret, x1 - n + 1);
    }

    cout << ret << "\n";

    return 0;
}