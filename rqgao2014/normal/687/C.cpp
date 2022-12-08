#include<bits/stdc++.h>
using namespace std;

int n,k,a[505];
bitset<555> dp[2][505];
vector<int> seq;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int d=0;
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		d^=1;
		for(int j=0;j<=500;j++){
			dp[d][j]=dp[d^1][j];
			if(j>=a[i]) dp[d][j]|=dp[d^1][j-a[i]];
			dp[d][j]|=dp[d^1][j]<<a[i];
		}
	}
	for(int i=0;i<=k;i++)
		if(dp[d][i][k-i]) seq.push_back(i);
	printf("%d\n",seq.size());
	for(int i=0;i<seq.size();i++)
		printf("%d ",seq[i]);
	return 0;
}
/*
3 50
25 25 50
*/