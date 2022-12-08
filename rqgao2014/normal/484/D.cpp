#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf=1ll<<60;
int n,a[1000005];
ll dp[2][3];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int k=0;
	dp[k][1]=0;
	dp[k][0]=dp[k][2]=-inf;
	for(int i=1;i<=n;i++){
		k^=1;
		for(int j=0;j<3;j++){
			dp[k][j]=dp[k^1][j];
			if(j) dp[k][j]=max(dp[k][j],dp[k^1][j-1]+a[i]);
			if(j<2) dp[k][j]=max(dp[k][j],dp[k^1][j+1]-a[i]);
		}
	}
	cout<<dp[k][1]<<endl;
	return 0;
}

/*
5
1 2 3 1 2
*/