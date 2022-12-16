// They can't break me, as long as I know who I am...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 5010, mod = 998244353;

int dp[maxn][maxn];

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a= 1ll * a* a %mod)
	if(b&1)
	    ans = 1ll * ans * a %mod;
    return ans;
}
int C(int n, int k){
    if(n < k)
	return 0;
    int A =1, B = 1;
    for(int i = 0; i < k; i++)
	A = 1ll * A * (n - i) %mod, B = 1ll * B * (i+1) %mod;
    return 1ll * A * Pow(B, mod -2) %mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    
    for(int i = 1; i < maxn; i++)
	dp[i][1] = 1;
    for(int i = 2; i < maxn; i++)
	for(int j = 2; j < maxn; j++)
	    dp[i][j] = 1ll * j * (dp[i-1][j] + dp[i-1][j-1]) %mod;
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for(int i = 1; i <= k; i++)
	ans = ( 1ll * ans + 1ll * C(n, i) * dp[k][i] %mod * Pow( m, mod-1-i ) ) %mod;
    return cout << ans << endl, 0;
}
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")