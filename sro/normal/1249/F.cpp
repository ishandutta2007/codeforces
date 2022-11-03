#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[205][205];
int a[205];
vector<int> nei[205];
int tmp[205];

void dfs(int now,int lst){
	dp[now][0]=a[now];
	for(int i=0;i<nei[now].size();i++){
		int to=nei[now][i];
		if(to==lst){
			continue;
		}
		dfs(to,now);
		memset(tmp,0,sizeof(tmp));
		for(int j=0;j<=m;j++){
			for(int k=m-j;k<=m;k++){
				tmp[min(j,k+1)]=max(tmp[min(j,k+1)],dp[now][j]+dp[to][k]);
			}
		}
		for(int j=m;j>=0;j--){
			dp[now][j]=max(dp[now][j+1],tmp[j]);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	dfs(1,0);
	printf("%d\n",dp[1][0]);
	return 0;
}