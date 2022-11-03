#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
char s[505];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	cin>>(s+1);
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i-1]=0;
		dp[i][i]=1;
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int k=i+1;k<=j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]-(s[k-1]==s[j]));
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}