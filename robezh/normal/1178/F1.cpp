#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;
const ll mod = 998244353;

int n, m;
ll fac[N], facinv[N];
ll inv[N];
int a[N];
ll dp1[N][N], dp2[N][N], dp3[N][N];
int mn[N][N];

void add(ll &to, ll val) {
    to += val;
    if(to >= mod) to -= mod;
}

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
}

ll calc_dp1(int l, int r);
ll calc_dp2(int lb, int r);

ll calc_dp2(int lb, int r) {
    if(lb > r) return 0;
    if(dp2[lb][r] != -1) return dp2[lb][r];
    ll res = 0;
    int mid = mn[lb][r];
    for(int rb = mid; rb <= r; rb++) {
        ll cur_res = 1;
        if(rb + 1 <= r) {
            cur_res *= calc_dp1(rb + 1, r);
            cur_res %= mod;
        }
        if(mid - 1 >= lb) {
            cur_res *= calc_dp1(lb, mid - 1);
            cur_res %= mod;
        }
        if(mid + 1 <= rb) {
            cur_res *= calc_dp1(mid + 1, rb);
            cur_res %= mod;
        }
        add(res, cur_res);
    }
    return dp2[lb][r] = res;
}

ll calc_dp1(int l, int r) {
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp1[l][r] != -1) return dp1[l][r];
    ll res = 0;
    for(int lb = l; lb <= mn[l][r]; lb++) {
        ll cur_res = calc_dp2(lb, r);
        if(l <= lb - 1) {
            cur_res *= calc_dp1(l, lb - 1);
            cur_res %= mod;
        }
        add(res, cur_res);
    }
    return dp1[l][r] = res;
}


int main(){
    init_fac();
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    memset(dp3, -1, sizeof(dp3));

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int l = 0; l < n; l++) {
        for(int r = l; r < n; r++) {
            mn[l][r] = l;
            for(int i = l; i <= r; i++) {
                if(a[i] < a[mn[l][r]]) mn[l][r] = i;
            }
        }
    }
    cout << (calc_dp1(0, n - 1) % mod + mod) % mod << endl;

}