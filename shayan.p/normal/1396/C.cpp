// Oh damn! Suddenly you're free to fly
// Shayan.P  2020-08-30

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
const ll inf = 1e18;

ll a[maxn];
ll dp[maxn][8];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    ll A, B, C, D;
    cin >> n >> A >> B >> C >> D;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    for(int i = 0; i < 8; i++){
	dp[n][i] = inf;
    }
    for(int i = n-1; i >= 0; i--){
	for(int msk = 0; msk < (1<<3); msk++){
	    dp[i][msk] = inf;
	    ll x = min(1ll * min(A, C) * (a[i]+1), B);
	    ll y = 1ll * min(A, C) * a[i] + C;
	    if(bit(msk, 2) == 0)
		dp[i][msk] = min(dp[i][msk], min(dp[i+1][msk << 1] + y + D, dp[i+1][(msk << 1) | 1] + x + D));
	    int cnt = 32 - __builtin_clz(msk);
	    cnt = max(cnt, int(1));
	    ll z = min(x + min({A, B, C}), y);
	    dp[i][msk] = min(dp[i][msk], z + min({A, B, C}) * __builtin_popcount(msk) + 1ll * (2 * cnt + 1) * D + dp[i+1][0]);
	    if(i == n-1){
		dp[i][msk] = min(dp[i][msk], z + min({A, B, C}) * __builtin_popcount(msk) + 1ll * (2 * cnt) * D);
		int cnt = 32 - __builtin_clz(msk);		
		dp[i][msk] = min(dp[i][msk], y + min({A, B, C}) * __builtin_popcount(msk) + 1ll * cnt * D);
	    }
	}
    }
    return cout << dp[0][0] << endl, 0;
}