#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 110, MAX = maxn * maxn, inf = 1e9;

int dp[2][maxn][MAX];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    for(int i = 0; i < maxn; i++)
	for(int j = 0; j < MAX; j++)
	    dp[0][i][j] = dp[1][i][j] = -inf;
    dp[0][0][0] = dp[1][0][0] = 0;
    
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
	int a, b;
	cin >> a >> b;
	sum+= b;
	int o = i&1, O = 1-o;
	for(int j = 1; j <= i; j++)
	    for(int k = 0; k <= maxn * i; k++)
		dp[o][j][k] = max(dp[O][j][k], k < a ? (-inf) : (b + dp[O][j-1][k-a]));
	int MX = -inf;
	for(int w = 9; w < MAX; w++)
	    MX = max(MX, dp[o][1][9]);
    }
    int o = n&1;
    for(int i = 0; i < maxn; i++)
	for(int j = MAX-2; j >= 0; j--)
	    dp[o][i][j] = max(dp[o][i][j], dp[o][i][j+1]);

    int ans = 0;
    for(int i = 1; i <= n; i++){
	while(ans <= 2*sum && dp[o][i][(ans+1)/2] >= ans-sum)
	    ans++;
	--ans;
	cout << setprecision(10) << fixed << 1.0*ans/2 << " ";
	++ans;
    }
    return 0;
}