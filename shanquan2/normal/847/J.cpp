#include<bits/stdc++.h>
using namespace std;

vector<int> a[5005];
bool vis[5005];
int ans,n,m;
bool dfs(int x,int y){
	if(vis[x])return 0;
	vis[x]=1;
	if(a[x].size()<ans)return a[x].push_back(y),1;
	for(int i=0;i<a[x].size();i++)if(dfs(a[x][i],x)){
		a[x][i]=y;
		return 1;
	}
	return 0;
}
bool solve(int x,int y){
	memset(vis,0,sizeof(vis));
	return dfs(x,y);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(!solve(x,y)&&!solve(y,x)){
			ans++;
			solve(x,y)||solve(y,x);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++)printf("%d %d\n",i,a[i][j]);
	}
	return 0;
}