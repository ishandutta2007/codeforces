#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=100000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
struct Edge{
	int to,nxt;
	Edge(int _to=0,int _nxt=0){
		to=_to;
		nxt=_nxt;
	}
}edge[Maxn<<1|5];
int head[Maxn+5],tot;
void add_edge(int from,int to){
	tot++;
	edge[tot].to=to;
	edge[tot].nxt=head[from];
	head[from]=tot;
}
int sz[Maxn+5],p[Maxn+5];
int sum[Maxn+5];
void init_dfs_0(int u,int fa){
	sz[u]=1;
	sum[u]=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa){
			continue;
		}
		init_dfs_0(v,u);
		sz[u]+=sz[v];
		sum[u]=(sum[u]+sum[v])%Mod;
	}
	sum[u]=(1ll*sum[u]*sz[u]+p[sz[u]])%Mod;
}
int f[Maxn+5][4];
void init_dfs_1(int u,int fa){
	int tmp_sum=sum[u],tmp_sz=sz[u];
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa){
			continue;
		}
		f[v][0]=sum[u];
		f[v][1]=sum[v];
		sum[u]=(Mod-sum[v]+1ll*(sum[u]-p[sz[u]]+Mod)*find_inv(sz[u]))%Mod;
		sz[u]-=sz[v];
		sum[u]=(1ll*sum[u]*sz[u]+p[sz[u]])%Mod;
		sum[v]=1ll*(sum[v]-p[sz[v]]+Mod)*find_inv(sz[v])%Mod;
		sz[v]+=sz[u];
		sum[v]=(1ll*(sum[u]+sum[v])*sz[v]+p[sz[v]])%Mod;
		f[v][2]=sum[u];
		f[v][3]=sum[v];
		init_dfs_1(v,u);
		sum[u]=tmp_sum;
		sz[u]=tmp_sz;
	}
}
int d[Maxn*5+5],num[Maxn*5+5];
int cnt;
int no,maxn,ans;
void add(int pos){
	no+=!(num[pos]++);
}
void del(int pos){
	no-=!(--num[pos]);
}
void init_dfs_2(int u,int fa){
	if(fa){
		del(lower_bound(d,d+cnt,f[u][0])-d);
		del(lower_bound(d,d+cnt,f[u][1])-d);
		add(lower_bound(d,d+cnt,f[u][2])-d);
		add(lower_bound(d,d+cnt,f[u][3])-d);
	}
	if(no>maxn){
		maxn=no;
		ans=u;
	}
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa){
			continue;
		}
		init_dfs_2(v,u);
	}
	if(fa){
		add(lower_bound(d,d+cnt,f[u][0])-d);
		add(lower_bound(d,d+cnt,f[u][1])-d);
		del(lower_bound(d,d+cnt,f[u][2])-d);
		del(lower_bound(d,d+cnt,f[u][3])-d);
	}
}
int rnk[Maxn+5];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		p[i]=1ll*i*i%Mod;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs_0(1,0);
	for(int i=1;i<=n;i++){
		d[cnt++]=rnk[i]=sum[i];
	}
	init_dfs_1(1,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			d[cnt++]=f[i][j];
		}
	}
	sort(d,d+cnt);
	cnt=unique(d,d+cnt)-d;
	for(int i=1;i<=n;i++){
		add(lower_bound(d,d+cnt,rnk[i])-d);
	}
	init_dfs_2(1,0);
	printf("%d\n",ans);
	return 0;
}