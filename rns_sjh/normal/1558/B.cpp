#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const double eps = 1e-8;
const int inf = 1e9 + 7;
const double dinf = 1e9 + 7.0;
const ll linf = 2e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define bi bigint
#define fi first
#define se second
#define BC __builtin_popcount
#define BL __builtin_clz
#define BT __builtin_ctz
#define forl(i, a, b) for(int i = a; i < b; i ++)
#define fore(i, a, b) for(int i = a; i <= b; i ++)
#define rforl(i, a, b) for(int i = a; i > b; i --)
#define rfore(i, a, b) for(int i = a; i >= b; i --)
#define Mod(a, b) (((a) % b) + b) % b
#define return(a) return flush(), a;

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg!=',')cerr<<*sdbg++;
    cerr<<" = "<<h<<','; _dbg(sdbg+1, a...);
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
    os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.x << "," << P.y << ")";
}

#define LOCAL
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

namespace FIO {
    inline char gc() {
        static char buf[100000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T> inline int read(T &x) {
        char c = gc(), b = 1;
        for (; !(c >= '0' && c <= '9' || c == EOF); c = gc()) if (c == '-') b = -b;
        if (c == EOF) return 0;
        for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = gc());
        x *= b;
        return 1;
    }
    inline int read(char *s) {
        char c = gc();
        int len = 0;
        for (; c <= ' ' && c != EOF; c = gc());
        if (c == EOF) return 0;
        for (; !(c <= ' '); s[len++] = c, c = gc());
        s[len] = 0;
        return 1;
    }
    template <typename Head, typename... Tail>
    inline int read(Head& H, Tail&... T) {
        int rlt = read(H);
        return rlt + read(T...);
    }
    inline void pc(char c) {
        static char buf[100000], *p1 = buf, *p2 = buf + 100000;
        if (!c) fwrite(buf, 1, p1 - buf, stdout), p1 = buf;
        else {
            *p1++ = c;
            p1 == p2&&(fwrite(buf, 1, 100000, stdout), p1 = buf);
        }
    }
    template <class T> inline void write(T x) {
        static char str[64];
        if (x == 0) pc('0');
        else {
            if (x < 0) pc('-'), x = -x;
            int sn = 0;
            while (x) str[sn++] = x % 10 + '0', x /= 10;
            for (int i = sn - 1; i >= 0; i --) pc(str[i]);
        }
    }
    inline void write(char c) {
        pc(c);
    }
    inline void write(char *s) {
        for (int i = 0; s[i]; i ++) pc(s[i]);
    }
    inline void write(const char *s) {
        for (int i = 0; s[i]; i ++) pc(s[i]);
    }
    template <typename Head, typename... Tail>
    inline void write(Head H, Tail... T) {
        write(H), write(T...);
    }
    inline void flush() {
        pc(0);
    }
}
using namespace FIO;

#define N 4000010
int dp[N], a[N];
int sum[N];

int main(){
    int n, m;
    read(n, m);
    sum[0] = 0;
    a[0] = 0;
    fore(i, 1, n){
        a[i] += a[i - 1];
        if(a[i] >= m) a[i] -= m;
        dp[i] = (sum[i - 1] + a[i]) % m;
        if(i == 1) dp[i] = 1;
        for(int j = 2; j * i <= n; j ++){
            a[i * j] += dp[i];
            if(a[i * j] >= m) a[i * j] -= m;
            if(i * j + j <= n) a[i*j+j] = (a[i*j+j] + m - dp[i]) % m;
        }
        sum[i] = sum[i - 1] + dp[i];
        if(sum[i] >= m) sum[i] -= m;

    }
    write(dp[n], '\n');
    return(0);
}