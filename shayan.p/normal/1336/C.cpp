// Never let them see you bleed...
// Shayan.P  2020-04-15

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 3010, mod = 998244353;

int dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    string a, b;
    cin >> a >> b;
    int n = sz(a), m = sz(b);
    while(sz(b) < n)
	b.PB('.');
    int ans = 0;
    for(int r = 0; r < n; r++){
	if(b[r] == '.' || b[r] == a[0])
	    dp[r][r] = 2;
	else
	    dp[r][r] = 0;	    
	for(int l = r-1; l >= 0; l--){
	    if(b[r] == '.' || b[r] == a[r-l])
		dp[l][r] = (dp[l][r] + dp[l][r-1]) % mod;
	    if(b[l] == '.' || b[l] == a[r-l])
		dp[l][r] = (dp[l][r] + dp[l+1][r]) % mod;
	}
	if(r+1 >= m)
	    ans = (ans + dp[0][r]) % mod;
    }
    return cout << ans << endl, 0;
}