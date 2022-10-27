#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
vector<int> g[N]; int n;
int dp[N][2],ans[N];
void dfs(int u,int p){
	dp[u][1]=1, dp[u][0]=0;
	int sonCnt=0;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u); sonCnt++;
	}
	for(auto v:g[u]){
		if(v==p)continue;
		dp[u][1]=max(dp[u][1],1+dp[v][0]);
		dp[u][0]=max(dp[u][0],max(dp[v][0]+sonCnt-1,dp[v][1]+sonCnt-1));
	}
	ans[u]=max(dp[u][0],dp[u][1]);
	{
		int mx1=0,mx2=0;
		for(auto v:g[u]){
			if(v==p)continue;
			if(dp[v][0]>=mx1){
				mx2=mx1,mx1=dp[v][0];
			}else if(dp[v][0]>mx2){
				mx2=dp[v][0];
			}
		}
		ans[u]=max(ans[u],mx1+mx2+1);
	}
	{
		int mx1=0,mx2=0;
		for(auto v:g[u]){
			if(v==p)continue;
			int val=max(dp[v][0],dp[v][1]);
			if(val>=mx1){
				mx2=mx1,mx1=val;
			}else if(val>mx2){
				mx2=val;
			}
		}
		ans[u]=max(ans[u],mx1+mx2+max(sonCnt-2,0)+(u>1?1:0));
	}
	//printf("%d  / %d %d\n", u,dp[u][0],dp[u][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		//u=i+1,v=rand()%i+1;
		//printf("%d %d\n", u,v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1,1);
	cout<<(*(max_element(ans+1,ans+1+n)))<<endl;
	return 0;
	int res=0;
	for(int i=1;i<=n;i++){
		dfs(i,i);
		res=max(res,max(dp[i][0],dp[i][1]));
		//printf("%d %d/%d\n", i,dp[i][0],dp[i][1]);
	}
	cout<<res<<endl;
	
}