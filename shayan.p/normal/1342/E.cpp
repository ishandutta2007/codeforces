// Never let them see you bleed...
// Shayan.P  2020-04-26

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10, mod = 998244353;

int Pow(int a, int b){
    int ans = 1;
    for(; b; b >>= 1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}

int fac[maxn], ifac[maxn];

int C(int n, int k){
    return 1ll * fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * i * fac[i-1] % mod;
    ifac[maxn-1] = Pow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)
	ifac[i] = 1ll * ifac[i+1] * (i+1) % mod;
    
    int n;
    ll k;
    cin >> n >> k;
    if(k >= n)
	return cout << 0 << endl, 0;
    if(k == 0)
	return cout << fac[n] << "\n", 0;
    int d = n - k, ans = 0;
    for(int i = 0; i <= d; i++){
	ans = (1ll * ans + 1ll * C(d, i) * Pow(i, n) * ((d-i) & 1 ? -1 : 1)) % mod;
    }
    ans = (ans + mod) % mod;
    return cout << 2ll * ans * C(n, d) % mod << "\n", 0;
}