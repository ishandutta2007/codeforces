#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=20005;
map<pii,int>ch;
int n,m;int totV=1;
int S=0;int T=1;int tot=1;
int head[N],np[N*20],flow[N*20],p[N*20];
int A[55],B[55],C[55],l[55],r[55];
const int inf=1e9;
const int Max=1e7;
inline void link(int a,int b,int c){
	tot++;p[tot]=b;np[tot]=head[a];head[a]=tot;flow[tot]=c;
	tot++;p[tot]=a;np[tot]=head[b];head[b]=tot;flow[tot]=0;
}
int q[N],dis[N];
int BFS(){
	memset(dis,-1,sizeof dis);
	q[q[0]=1]=S;
	dis[S]=0;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if(flow[u]&&dis[p[u]]==-1){
			dis[p[u]]=dis[x]+1;
			q[++q[0]]=p[u];
		}
	}
	return dis[T];
}
int dinic(int x,int fl){
	int ret=0;
	if(x==T)return fl;
	for(int u=head[x];u;u=np[u])if(flow[u]&&dis[p[u]]==dis[x]+1){
		int tmp=dinic(p[u],min(fl,flow[u]));
		flow[u]-=tmp;flow[u^1]+=tmp;ret+=tmp;fl-=tmp;
	}
	return ret;
}		
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d%d%d",&A[i],&B[i],&C[i]);
	rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
	rep(i,1,n){
		rep(j,l[i]-1,r[i]){
			pii fuck=pii(i,j);
			ch[fuck]=++totV;
			if(j==l[i]-1)link(S,totV,inf);
			else link(totV-1,totV,Max-(A[i]*j*j+B[i]*j+C[i]));
		}
		link(totV,T,inf);
	}
	while(m--){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		rep(i,l[u]-1,r[u])if(i-d>=l[v]-1&&i-d<=r[v]){
			pii f1=pii(u,i);
			pii f2=pii(v,i-d);
			link(ch[f1],ch[f2],inf);
		}
	}
	int ans=0;
	while(BFS()!=-1){
		ans+=dinic(S,inf);
	}
	printf("%d\n",Max*n-ans);
	return 0;
}