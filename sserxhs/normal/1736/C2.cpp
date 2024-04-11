#include<bits/stdc++.h>
#define ll long long
#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN], d[MN], n, m;
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    REP(i, 1, n + 1) a[i] = read(), b[i] = i; b[0] = 1;
    int j = 0;
    long long ans = 0;
    REP(i, 1, n + 1) {
        while(j + 1 <= n && a[j + 1] - j - 1 >= 1 - i) ++j, b[j] = min(b[j], i);
        ans += j - i + 1;
        c[i] = j;
    }
    j = 0;
    REP(i, 1, n + 1) {
        j = min(n, max(j, c[i] + 1));
        while(j + 1 <= n && a[j + 1] - j - 1 >= 1 - i) ++j;
        d[i] = j - c[i];
    }

    REP(i, 1, n + 1) c[i] = c[i] - i + 1 + c[i - 1];
    REP(i, 1, n + 1) d[i] = d[i] + d[i - 1];
    // printf("%lld\n", ans);
    m = read();
    while(m--) {
        int pos = read();
        int x = read();
        if(a[pos] == x) printf("%lld\n", ans);
        else if(a[pos] > x) {
            int upd = max(b[pos], pos - x + 1);
            long long anss = ans - c[upd - 1] + c[b[pos] - 1];
            anss += 1ll * (pos - upd + 1 + pos - b[pos]) * (upd - b[pos]) / 2;
            printf("%lld\n", anss);
        }
        else {
            int upd = max(b[pos - 1], pos - x + 1);
            long long anss = ans + d[b[pos] - 1] - d[upd - 1];
            printf("%lld\n", anss);
        }
    }
    return 0;
}//jk