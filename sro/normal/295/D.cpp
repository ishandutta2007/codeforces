/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

template<int jt> struct ModInt {
    int x;
    ModInt(int v = 0) {x = v; if(x >= jt || x < 0) {x %= jt; if(x < 0) x += jt;}}
    ModInt(ll v) {x = v % jt; if(x < 0) x += jt;}
    operator int() const {return x;}
    friend inline ModInt &operator+=(ModInt &a, const ModInt &b) {a.x += b.x; if(a.x >= jt) a.x -= jt; return a;}
    friend inline ModInt operator+(ModInt a, const ModInt &b) {return a += b;}
    friend inline ModInt operator+(ModInt a, int b) {return a += ModInt(b);}
    friend inline ModInt operator+(int a, ModInt b) {return b += ModInt(a);}
    friend inline ModInt &operator++(ModInt &a) {return a += 1;}
    friend inline ModInt &operator-=(ModInt &a, const ModInt &b) {a.x -= b.x; if(a.x < 0) a.x += jt; return a;}
    friend inline ModInt operator-(ModInt a, const ModInt &b) {return a -= b;}
    friend inline ModInt operator-(ModInt a, int b) {return a -= ModInt(b);}
    friend inline ModInt operator-(int a, ModInt b) {return ModInt(a) - b;}
    friend inline ModInt &operator--(ModInt &a) {return a -= 1;}
    friend inline ModInt &operator*=(ModInt &a, const ModInt &b) {a.x = (ll)a.x * b.x % jt; return a;}
    friend inline ModInt operator*(ModInt a, const ModInt &b) {return a *= b;}
    friend inline ModInt operator*(ModInt a, int b) {return a *= ModInt(b);}
    friend inline ModInt operator*(int a, ModInt b) {return b *= ModInt(a);}
    static inline void exgcd(ll a, ll b, ll &x, ll &y) {b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);}
    friend inline ModInt inv(const ModInt &a) {ll x, y; exgcd(a, jt, x, y); return x;}
    friend inline ModInt operator/(const ModInt &a, const ModInt &b) {return a * inv(b);}
    friend inline ModInt operator/(ModInt a, int b) {return a * inv(ModInt(b));}
    friend inline ModInt operator/(int a, ModInt b) {return ModInt(a) * inv(b);}
    friend inline ModInt operator/=(ModInt &a, const ModInt &b) {return a = a / b;}
};
const int jt = 1000000007;
typedef ModInt<jt> mint;

int n, m;
mint dp[2333][2333], pre[2333][2333], prs[2333][2333];
mint srs[2333][2333];

int main() {
    scanf("%d%d", &n, &m);
    dp[0][0] = prs[0][0] = 1;
    cont(j, m) {
        pre[0][j] = pre[0][j - 1] + dp[0][j];
        prs[0][j] = prs[0][j - 1] + pre[0][j];
    }
    cont(i, n) dp[i][0] = prs[i][0] = 1;
    cont(i, n) cont(j, m) {
        dp[i][j] = prs[i - 1][j];
        pre[i][j] = pre[i][j - 1] + dp[i][j];
        prs[i][j] = prs[i][j - 1] + pre[i][j];
    }
    mint ans = 0;
    cont(i, n) cont(j, m - 1) ans += (m - j) * (dp[i][j] - dp[i - 1][j]) * dp[n - i + 1][j];
    return 0 & printf("%d\n", int(ans));
}