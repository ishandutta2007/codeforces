#include<cstdio>
#include<vector>
using namespace std;

vector<int> to[100000],len[100000];
int fa[100000],st[100000],en[100000],lgh[100000],siz[100000],n;
long long ans;
bool vis[100000]={0};
void dfs(int x){
	siz[x]=1;vis[x]=1;
	for(int i=0;i<to[x].size();i++)if(!vis[to[x][i]]){
		int u=to[x][i];
		dfs(u);
		siz[x]+=siz[u];
		ans+=(long long)len[x][i]*(long long)siz[u]*(long long)(n-siz[u]);
		fa[u]=x;
	}
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y,l;scanf("%d%d%d",&x,&y,&l);x--,y--;
		to[x].push_back(y);len[x].push_back(l);
		to[y].push_back(x);len[y].push_back(l);
		st[i]=x,en[i]=y;lgh[i]=l;
	}
	ans=0;
	dfs(0);
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		int id,l;scanf("%d%d",&id,&l);
		int u=st[id],v=en[id];
		if(fa[u]==v){
			int t=u;u=v;v=t;
		}
		ans+=(long long)(l-lgh[id])*siz[v]*(n-siz[v]);
		lgh[id]=l;
		printf("%.9lf\n",(double)ans/(double)n*6.0/(double)(n-1));
	}
	return 0;
}