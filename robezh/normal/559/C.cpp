#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

ll fac[200500], facinv[200500];
int h,w,n;
int x[2005], y[2005];
ll dp[2005];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k%2 ? hf*hf%mod*x%mod : hf*hf%mod;
}

ll Comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n-k] % mod;
}

bool should(int i, int j){
    return x[j] <= x[i] && y[j] <= y[i];
}

ll get(int i){
    if(dp[i] != -1) return dp[i];

    ll res = Comb(x[i]+y[i]-2, x[i]-1);
    for(int j = 1; j <= n; j++){
        if(i != j && should(i,j)) res = (res - get(j)*Comb(x[i]-x[j]+y[i]-y[j], x[i]-x[j])%mod+ mod) % mod;
    }
    return dp[i] = res;

}

int main(){
    fac[0] = 1;
    for(int i = 1; i <= 200000; i++) fac[i] = fac[i-1] * i % mod;
    facinv[200000] = fp(fac[200000], mod-2);
    for(int i = 200000 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    fill(dp, dp+2005, -1);
    scanf("%d%d%d", &h, &w, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    //cout << facinv[1] << endl;
    x[0] = h, y[0] = w;
    cout << get(0) << endl;

}