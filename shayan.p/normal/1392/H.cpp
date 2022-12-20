// And you curse yourself for things you never done
// Shayan.P  2020-08-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 4e6 + 10, mod = 998244353, inf = 1e9 + 10;

int dp[maxn], ifac[maxn], fac[maxn], inum[maxn];

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % mod)
	if(b & 1)
	    ans = 1ll * ans * a % mod;
    return ans;
}
int C(int n, int k){
    if(n < k)
	return 0;
    return 1ll * fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}
int IC(int n, int k){
    if(n < k)
	return 0;
    return 1ll * ifac[n] * fac[k] % mod * fac[n-k] % mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    fac[0] = 1;
    for(int i = 1; i < maxn; i++)
	fac[i] = 1ll * i * fac[i-1] % mod;
    ifac[maxn-1] = Pow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)
	ifac[i] = 1ll * ifac[i+1] * (i+1) % mod;
    for(int i = 1; i < maxn; i++)
	inum[i] = 1ll * ifac[i] * fac[i-1] % mod; 
    int n, m;
    cin >> n >> m;
    int sm = 0;
    for(int i = 1; i <= n; i++){
	dp[i] = (sm + C(i+m, i)) % mod;
	sm = (1ll * sm + 1ll * dp[i] * m % mod * inum[i]) % mod;
	dp[i] = 1ll * dp[i] * IC(i+m-1, m) % mod;
    }
    return cout << 1ll * dp[n] * (n+m+1) % mod * Pow(m+1, mod-2) % mod << endl, 0;
}