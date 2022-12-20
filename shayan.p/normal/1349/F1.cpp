// Never let them see you bleed...
// Shayan.P  2020-05-12

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 5010, mod = 998244353, inf = 1e9 + 10;

int dp[maxn][maxn], ans[maxn], ifac[maxn];

int Pow(int a, int b){
    int ans = 1;
    for(; b; b>>=1, a = 1ll * a * a % mod)
	if(b&1)
	    ans = 1ll * ans * a % mod;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    int fac = 1;
    for(int i = 1; i <= n; i++){
	fac = 1ll * i * fac % mod;
	ifac[i] = Pow(fac, mod-2);
    }
    dp[1][0] = 1;
    for(int i = 1; i <= n; i++){
	for(int j = 0; j < i; j++){
	    dp[i+1][j] = (1ll * dp[i+1][j] + 1ll * dp[i][j] * (j+1)) % mod;
	    dp[i+1][j+1] = (1ll * dp[i+1][j+1] + 1ll * dp[i][j] * (i-j)) % mod;
	    ans[j] = (1ll * ans[j] + 1ll * fac * ifac[i] % mod * dp[i][j]) % mod;
	}
    }
    for(int i = 0; i < n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}