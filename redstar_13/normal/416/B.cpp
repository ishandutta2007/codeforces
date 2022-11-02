#include<bits/stdc++.h>

#define NN 55000

using namespace std;



int dp[NN][6],t[NN][6];

int main(){

//	freopen("in.txt","r",stdin);

	

	int n,m;

	cin>>m>>n;

	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",&t[i][j]);

	for(int i=1;i<=n;i++) dp[1][i]=dp[1][i-1]+t[1][i];

	for(int i=1;i<=m;i++) dp[i][1]=dp[i-1][1]+t[i][1];

	

	for(int i=1;i<=m;i++)

	for(int j=1;j<=n;j++)

		dp[i][j]=max(dp[i][j-1],dp[i-1][j])+t[i][j];

		

	for(int i=1;i<=m;i++)

		printf("%d ",dp[i][n]);

	return 0;



}