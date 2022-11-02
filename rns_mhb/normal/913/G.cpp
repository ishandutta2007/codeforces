#include <bits/stdc++.h>
using namespace std;
#define N 15
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mod(x,n) (((x)%(n)+(n))%(n))

ll mod_mul(ll x, ll y, ll mod){
    if( x == 0 || y == 0 ) return 0;
    x = (x + mod) % mod, y = (y + mod) % mod;
    ll ret = 0;
    while(x){
        ret = (ret + (x & 1) * y) % mod;
        y = (y << 1) % mod;
        x >>= 1;
    }
    return (ret + mod) % mod;
}

ll expmod(ll a,ll b,ll n) {
    ll re = 1,y = a%n;
    while (b) {
        if (b % 2) re = mod_mul(re, y, n);
        b >>= 1,y = mod_mul(y, y, n);
    }
    return re;
}
ll gcd(ll a,ll b,ll &x,ll &y) {
    if (!b) {
        x = 1,y = 0;
        return a;
    }
    else {
        ll tp,bx,by;
        tp = gcd(b, a%b ,x,y);
        bx = x,by = y;
        y=bx-(a/b)*by, x=by;
        return tp;
    }
}
ll inv(ll a,ll n) {
    ll x,y,tp;
    tp=gcd(a,n,x,y);
    if (tp==1) return mod(x,n);
    else return -1;
}

ll fv[20];
ll lg[10] = {0, 0, 1, 3, 2};

ll func(ll b, ll n) {
    if (n == 1) return lg[b%5];
    ll tmp = func(b, n - 1);
    ll r = expmod(2, tmp, fv[n]);
    int t = 0;
    while ((b % fv[n]) != mod_mul(r, 1 + 3 * fv[n-1] * t, fv[n])) t ++;
    tmp += 4 * fv[n-2] * t;
    return tmp;
}


int n;
ll a;

int main() {
    fv[0] = 1;
    for (int i = 1; i < 19; i ++) fv[i] = fv[i-1] * 5;
    scanf("%d", &n);
    while (n --) {
        scanf("%I64d", &a);
        int l = (int) log10(a) + 1;
        ll b = (a + 1) * 1000000 - 1;
        l += 6;
        b >>= l;
        ll ans;
        if (b % 5 == 0) b --;
        ans = func(b, l);
        cout<<ans + l<<endl;
    }
    return 0;
}