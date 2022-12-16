// And you curse yourself for things you never done
// Shayan.P  2020-08-09

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int a[maxn];
int dp[maxn][8];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    if(min(n, m) >= 4)
	return cout << -1 << endl, 0;
    for(int i = 0; i < n; i++){
	string s;
	cin >> s;
	for(int j = 0; j < m; j++){
	    int x = s[j] == '1';
	    if(n < m)
		a[j]|= x<<i;
	    else
		a[i]|= x<<j;
	}
    }
    if(n < m)
	swap(n, m);
    for(int msk = 0; msk < (1<<m); msk++)
	dp[0][msk] = __builtin_popcount(msk ^ a[0]);
    for(int i = 1; i < n; i++){
	for(int msk = 0; msk < (1<<m); msk++){
	    dp[i][msk] = inf;
	    for(int msk2 = 0; msk2 < (1<<m); msk2++){
		int MSK = msk ^ msk2;
		int ALL = (1<<(m-1)) - 1;
		if(((MSK ^ (MSK >> 1)) & ALL) == ALL)
		    dp[i][msk] = min(dp[i][msk], __builtin_popcount(msk ^ a[i]) + dp[i-1][msk2]);
	    }
	}
    }
    int ans = inf;
    for(int msk = 0; msk < (1<<m); msk++){
	ans = min(ans, dp[n-1][msk]);
    }
    if(ans == inf){
	ans = -1;
    }
    return cout << ans << endl, 0;
}