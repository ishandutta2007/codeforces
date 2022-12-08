#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#define sqr(x) (x)*(x)
#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define check cout<<"ISOK"<<endl
#define mod 1000000007
using namespace std;

vector<int> g[100005];
int n,m,next[100005],col[100005],u[100005],v[100005],tot;
bool vis[100005];
inline int find(int x){
	if(next[x]!=x) next[x]=find(next[x]);
	return next[x];
}
bool dfs(int x){
	vis[x]=true;
	bool isok=true;
	for(int i=0;i<g[x].size();i++)
		if(!vis[g[x][i]]) {col[g[x][i]]=col[x]^1;isok&=dfs(g[x][i]);} else if(col[g[x][i]]==col[x]) return false;
	return isok;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	 	next[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(!z){
//			g[x].pb(y);
//			g[y].pb(x);
			u[++tot]=x;v[tot]=y;
		}
		else next[find(x)]=find(y);
	}
	bool isok=true;
	for(int i=1;i<=tot;i++){
		g[find(u[i])].pb(find(v[i]));
		g[find(v[i])].pb(find(u[i]));
	}
	for(int i=1;i<=n;i++)
		if(!vis[find(i)]) isok&=dfs(find(i));
	for(int i=1;i<=tot;i++)
		if(find(u[i])==find(v[i])) isok=false; 
	for(int i=1;i<=tot;i++)
		next[find(u[i])]=find(v[i]);
	if(!isok){
		puts("0");
		return 0;
	}
	else{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			vis[find(i)]=true;
		int ans=1;
		isok=false;
		for(int i=1;i<=n;i++)
			if(vis[i]&&isok){
				ans=ans+ans;
				if(ans>mod) ans-=mod;
			}
			else if(vis[i]) isok=true;
		printf("%d\n",ans);
	}
	return 0;
}