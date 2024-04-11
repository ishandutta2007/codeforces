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

int n;
long long a, r, m, h[100005];

long long f(long long x) {
    int lcnt = 0, rcnt = 0;
    long long lsum = 0, rsum = 0;
    for (int i=0; i<n; i++) {
        if (h[i] < x) lcnt++, lsum += h[i];
        else if (h[i] > x) rcnt++, rsum += h[i];
    }
    long long lneed = x * lcnt - lsum, rneed = rsum - x * rcnt, diff = min(lneed, rneed);
    return min(lneed * a + rneed * r, min(lneed, rneed) * m + (lneed - diff) * a + (rneed - diff) * r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> r >> m;
    for (int i=0; i<n; i++)
        cin >> h[i];

    long long l = 0, r = 1e9 + 5;
    while (r - l > 5) {
        long long m = (l + r) / 2;
        if (f(m) > f(m + 1))
            l = m + 1;
        else
            r = m;
    }

    long long ret = LLONG_MAX;
    for (long long x=l; x<=r; x++)
        ret = min(ret, f(x));
    cout << ret << "\n";

    return 0;
}