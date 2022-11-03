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

char L[1 << 17], R[1 << 17];
mint mii[1 << 18], mio[1 << 18], s7[1 << 18], s4[1 << 18];
mint sm[1 << 18], sm2[1 << 18], sms[1 << 18], sx[1 << 18], sy[1 << 18];
int llen, rlen;

mint getr(char R[], int rlen) {
    mint ans = 0;
    cont(i, rlen - 1) {
        ans += sms[i];
        if(i != rlen - 1) ans += s7[i] * s4[i + 1];
    }
    mint pre = 0, prs = s7[rlen];
    loop(i, rlen) {
        int w = rlen - i - 1;
        if(R[i] == '7') {
            mint cur = pre + 4 * mio[w];
            ans += (cur + s4[w]) * prs;
            ans += cur * cur * (mii[w] - 1);
            ans += cur * (2 * sm[w] - s4[w] - s7[w]);
            ans += sms[w];
            prs = cur + s7[w];
            pre = pre + 7 * mio[w];
        } else {
            pre = pre + 4 * mio[w];
        }
    }
    ans += pre * prs;
    return ans;
}

int main() {
    scanf("%s", L); llen = strlen(L);
    scanf("%s", R); rlen = strlen(R);
    mii[0] = mio[0] = 1;
    cont(i, rlen) {
        mii[i] = mii[i - 1] * 2;
        mio[i] = mio[i - 1] * 10;
        s7[i] = s7[i - 1] * 10 + 7;
        s4[i] = s4[i - 1] * 10 + 4;
        sx[i] = sm[i - 1] * 10 + 4 * mii[i - 1];
        sy[i] = sm[i - 1] * 10 + 7 * mii[i - 1];
        sm[i] = sx[i] + sy[i];
        sm2[i] = sm2[i - 1] * 200 + sm[i - 1] * 220 + mii[i - 1] * 65;
        sms[i] = sm2[i - 1] * 100 + sm[i - 1] * 110 + mii[i - 1] * 28;
        sms[i] += sms[i - 1] * 100 + (sm[i - 1] - s4[i - 1]) * 70 + (sm[i - 1] - s7[i - 1]) * 40 + (mii[i - 1] - 1) * 28;
    }
    printf("%d\n", int(getr(R, rlen) - getr(L, llen)));
    return 0;
}