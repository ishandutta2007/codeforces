#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=210000;
const int P=1000000007;
int n,x[N],y[N];
map<int,int>dx,dy;
int M;
int head[N],np[N<<1],p[N<<1],tot;
int du[N];
int vis[N];
int Sd,Sb;
void add(int x,int y){
	if(!dx[x])dx[x]=++M;
	if(!dy[y])dy[y]=++M;
	x=dx[x];y=dy[y];
	++tot;p[tot]=y;np[tot]=head[x];head[x]=tot;
	++tot;p[tot]=x;np[tot]=head[y];head[y]=tot;
	du[x]++;
	du[y]++;
}
void dfs(int x){
	Sd++;
	Sb+=du[x];
	vis[x]=1;
	for(int u=head[x];u;u=np[u])if(!vis[p[u]]){
		dfs(p[u]);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
	rep(i,1,n)add(x[i],y[i]);
	int ans=1;
	rep(i,1,M)if(!vis[i]){
		Sd=Sb=0;
		dfs(i);
		int w=1;
		rep(j,1,Sd)w=w*2%P;
		if(Sd*2-2==Sb){
			ans=ans*1ll*(w+P-1)%P;
		}
		else ans=ans*1ll*w%P;
	}
	printf("%d\n",ans);
	return 0;
}