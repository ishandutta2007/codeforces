#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=5055;
int n,m;
int ax[N],ay[N];
//flow
int head[N],np[N*8],p[N*8],flow[N*8],tot;
int S,T;
void init(){
	rep(i,1,tot)flow[i]=p[i]=np[i]=0;
	rep(i,1,T)head[i]=0;
	tot=1;
	S=n+1;T=n+2;
}
inline int add(int a,int b,int c){
	++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;flow[tot]=c;
	++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;
	return tot;
}
int dis[N];
int q[N];
int dinic(int x,int ff){
	if(!ff)return 0;
	if(x==T)return ff;
	int ret=0;
	for(int u=head[x];u;u=np[u])if(dis[p[u]]==dis[x]+1)if(flow[u]){
		int tmp=dinic(p[u],min(ff,flow[u]));
		ff-=tmp;
		ret+=tmp;
		flow[u]-=tmp;
		flow[u^1]+=tmp;
		if(!ff)break;
	}
	if(!ret)dis[x]=-1;
	return ret;
}
int bfs(){
	rep(i,1,T)dis[i]=-1;
	dis[S]=0;
	q[q[0]=1]=S;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=np[u])if(flow[u])if(dis[p[u]]==-1){
			dis[p[u]]=dis[x]+1;
			q[++q[0]]=p[u];
		}
	}
	return dis[T];
}
//flow-end
int du[N];
bool check(int dd){
	memset(du,0,sizeof du);
	rep(i,1,m)du[ax[i]]++;

	init();
	int need=0;
	rep(i,1,n){
		if(du[i]>dd){
			add(S,i,du[i]-dd);
			need+=du[i]-dd;
		}
		else if(du[i]<dd)add(i,T,dd-du[i]);
	}
	rep(i,1,m)add(ax[i],ay[i],1);

	while(bfs()!=-1)need-=dinic(S,1e9);
	return !need;
}
int id[N];
void prtans(int dd){
	memset(du,0,sizeof du);
	rep(i,1,m)du[ax[i]]++;

	init();
	int need=0;
	rep(i,1,n){
		if(du[i]>dd){
			add(S,i,du[i]-dd);
			need+=du[i]-dd;
		}
		else if(du[i]<dd)add(i,T,dd-du[i]);
	}
	rep(i,1,m)id[i]=add(ax[i],ay[i],1);

	while(bfs()!=-1)need-=dinic(S,1e9);

	rep(i,1,m)if(flow[id[i]])printf("%d %d\n",ay[i],ax[i]);
	else printf("%d %d\n",ax[i],ay[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m)scanf("%d%d",&ax[i],&ay[i]);

	int l=0;int r=n;
	int ans=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid+1;
	}
	if(check(l))ans=l;

	printf("%d\n",ans);
	prtans(ans);
	return 0;
}