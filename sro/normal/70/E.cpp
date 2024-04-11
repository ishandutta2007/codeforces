#include <bits/stdc++.h>
using namespace std;

int n,m;
int cost[188];
int dis[188][188];
int dp[188][188];
int sel[188];
vector<int> nei[188];
int chs[188];

void dfs(int now,int lst){
	for(int i=1;i<=n;i++){
		dp[now][i]=cost[dis[now][i]]+m;
	}
	for(int i=0;i<nei[now].size();i++){
		int to=nei[now][i];
		if(to==lst){
			continue;
		}
		dfs(to,now);
		for(int j=1;j<=n;j++){
			dp[now][j]+=min(dp[to][j]-m,dp[to][sel[to]]);
		}
	}
	sel[now]=1;
	for(int i=1;i<=n;i++){
		if(dp[now][sel[now]]>dp[now][i]){
			sel[now]=i;
		}
	}
}

void getans(int now,int lst,int se){
	chs[now]=se;
	for(int i=0;i<nei[now].size();i++){
		int to=nei[now][i];
		if(to==lst){
			continue;
		}
		getans(to,now,dp[to][se]-m<dp[to][sel[to]]?se:sel[to]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<n;i++){
		scanf("%d",cost+i);
		dis[i][i]=0;
	}
	dis[n][n]=0;
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(b);
		nei[b].push_back(a);
		dis[a][b]=dis[b][a]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	dfs(1,0);
	printf("%d\n",dp[1][sel[1]]);
	getans(1,0,sel[1]);
	for(int i=1;i<=n;i++){
		printf("%d ",chs[i]);
	}
	puts("");
	return 0;
}