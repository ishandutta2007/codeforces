#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll big_rand(ll m) {
    return 1ll * rand() * rand() % m;
}

ll multi(ll x, ll y, ll m, int d = 1) {
    if(!x || !y) return 0;
    return (((x & ((1ll << d) - 1)) * y) % m + (multi(x >> d, y, m, d) << d) % m) % m;
}

ll mod_mul(ll x, ll y, ll m) {
    int d = 63 - __builtin_clzll(m) + 1;
    return d <= 31 ? x * y % m : multi(x, y, m, 63 - d);
}

ll expmod(ll x, ll y, ll m) {
    ll rlt = 1;
    while(y) {
        if(y & 1) rlt = mod_mul(rlt, x, m);
        x = mod_mul(x, x, m), y >>= 1;
    }
    return rlt;
}

bool Miller_Rabbin(ll n) {
    if(n == 2) return 1;
    if(n < 2 || !(n & 1)) return 0;
    int k = __builtin_ctzll(n - 1);
    ll m = n >> k;
    int step = 7;
    for(int i = 0, j; i < step; i ++) {
        ll x = big_rand(n - 2) + 2;
        x = expmod(x, m, n);
        if(x == 1) continue;
        for(j = 0; j < k; j ++) {
            if(x == n - 1) break;
            x = mod_mul(x, x, n);
        }
        if(j >= k) return 0;
    }
    return 1;
}

ll gcd(ll x, ll y) {
    while(y) {
        ll z = x % y;
        x = y, y = z;
    }
    return x;
}

ll func(ll x, ll m) {
    return (mod_mul(x, x, m) + 1) % m;
}

ll Pollard(ll n) {
    if(Miller_Rabbin(n)) return n;
    if(!(n & 1)) return 2;
    for(ll i = 1; ; i ++) {
        ll x = i, y = func(x, n), rlt = gcd(y - x, n);
        while(rlt == 1) {
            x = func(x, n);
            y = func(func(y, n), n);
            rlt = gcd((y - x + n) % n, n) % n;
        }
        if(rlt > 0 && rlt < n) return rlt;
    }
}

vector <ll> pf;

void go(ll x) {
    ll y = Pollard(x);
    if(y == x) {
        pf.push_back(y);
        return;
    }
    go(y), go(x / y);
}

ll a[33];
int b[33], cnt;

void prime_factorization(ll m) {
    pf.clear();
    go(m);
    sort(pf.begin(), pf.end());
    cnt = 0;
    for(int i = 0; i < pf.size(); i ++) {
        if(!i || pf[i] != pf[i-1]) a[++cnt] = pf[i], b[cnt] = 1;
        else b[cnt] ++;
    }
}

const int mod = 1e9 + 7;

int powmod(int x, int y) {
    int ret = 1;
    while(y) {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}


vector <ll> d;
vector <int> c;

#define N 20010

int fac[N], rfac[N];
int dp[100][N];

int H(int m, int k) {
    return 1ll * fac[m+k-1] * rfac[k] % mod * rfac[m-1] % mod;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    rfac[N-1] = powmod(fac[N-1], mod - 2);
    for(int i = N - 1; i; i --) rfac[i-1] = 1ll * rfac[i] * i % mod;
    ll n;
    int k;
    scanf("%I64d%d", &n, &k);
    if(n == 1) {
        puts("1");
        return 0;
    }
    prime_factorization(n);
    int ans = 1;
    for(int i = 1; i <= cnt; i ++) {
        for(int j = 0; j <= b[i]; j ++) dp[j][0] = powmod(a[i]%mod, j);
        for(int j = 1; j <= k; j ++) {
            dp[0][j] = dp[0][j-1];
            for(int h = 1; h <= b[i]; h ++) {
                dp[h][j] = dp[h-1][j] + dp[h][j-1];
                if(dp[h][j] >= mod) dp[h][j] -= mod;
            }
            for(int h = 0; h <= b[i]; h ++) dp[h][j] = 1ll * dp[h][j] * powmod(h+1, mod - 2) % mod;
        }
        ans = 1ll * ans * dp[b[i]][k] % mod;
    }
    printf("%d\n", ans);
}