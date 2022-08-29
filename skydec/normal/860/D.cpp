#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=420000;
int head[N],np[N],p[N],id[N],tot;
inline void add(int a,int b,int c){
	++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;id[tot]=c;
}
int wx[N],wy[N];
bool ff[N];
bool bb[N];
int n,m;
bool vis[N];
void dfs(int x){
	vis[x]=1;
	for(int u=head[x];u;u=np[u])if(!vis[p[u]]){
		dfs(p[u]);
		if(ff[p[u]]){
			ff[x]^=1;
			ff[p[u]]^=1;
			bb[id[u]]^=1;
		}
	}
}
int q[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&wx[i],&wy[i]);
		add(wx[i],wy[i],i);
		add(wy[i],wx[i],i);
		ff[wx[i]]^=1;
	}
	rep(i,1,n)if(!vis[i])dfs(i);
	int ans=m;
	rep(i,1,n)if(ff[i])--ans;
	printf("%d\n",ans/2);
	rep(x,1,n){
		q[0]=0;
		for(int u=head[x];u;u=np[u])if((wy[id[u]]!=x)^(bb[id[u]])){
			q[++q[0]]=(wx[id[u]]^wy[id[u]]^x);
		}
		//printf("%d %d\n",x,q[0]);
		for(int i=1;i<=q[0]-1;i+=2)printf("%d %d %d\n",q[i],x,q[i+1]);
	}
	return 0;
}