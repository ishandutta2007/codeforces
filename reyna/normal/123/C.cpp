//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 205;
const long long oo = 1e18 + 1;
int mat[Maxn][Maxn];
pair<int,int> diag[Maxn];
int ans[Maxn];
long long dp[Maxn][Maxn];
long long go(int n){
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i = 1; i <= n;i++){
		if(ans[i - 1] != 2) for(int k = 1; k <= n;++k) dp[i][k] = min(oo,dp[i][k] + dp[i-1][k-1]);
		if(ans[i - 1] != 1) for(int k = 0; k <= n;++k) dp[i][k] = min(oo,dp[i][k] + dp[i-1][k+1]);
	}
	return dp[n][0];
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	long long k;
	cin >> n >> m >> k;
	for(int i = 0; i < n + m - 1;i++) diag[i] = make_pair(Maxn * Maxn,i);
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++){
			int p;
			cin >> p;
			diag[i + j] = min(diag[i + j],make_pair(p,i+j));
		}
	sort(diag,diag + n + m - 1);
	for(int i = 0; i < n + m - 1;i++){
		int id = diag[i].second;
		ans[id] = 1;
		long long cur = go(n + m - 1);
		if(cur >= k) continue;
		ans[id] = 2;
		k -= cur;
	}
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++)
			if(ans[i + j] == 1) cout << '(';
			else cout << ')';
		cout << '\n';
	}
}