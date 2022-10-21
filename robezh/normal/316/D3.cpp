#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;
const ll mod = (ll)1e9 + 7;

int n, num[N], cnt1 = 0, cnt2 = 0;
ll fac[N], facinv[N];
ll inv[N];
ll I[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == 1) cnt1++;
        else cnt2++;
    }
    I[0] = 1;
    for(int i = 1; i <= cnt1; i++) {
        I[i] = I[i-1];
        if(i >= 2) I[i] = (I[i] + (i - 1) * I[i-2]) % mod;
    }
    cout << I[cnt1] * fac[n] % mod * facinv[cnt1] % mod << endl;
}