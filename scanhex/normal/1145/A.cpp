#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>a(n);
	for(auto&x:a)cin>>x;
	vector<vector<int>>dp(n,vector<int>(n+1));
	for(int len=1;len<=n;++len)
		for(int i=0;i+len<=n;++i){
			 int j=i+len;
			 if(is_sorted(a.begin()+i,a.begin()+j))
				 dp[i][j]=j-i;
			 else{
				 int m=(i+j)/2;
				 dp[i][j]=max(dp[i][m],dp[m][j]);
			 }
		}
	cout<<dp[0][n]<<'\n';
	return 0;
}