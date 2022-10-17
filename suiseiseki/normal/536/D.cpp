#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
typedef long long ll;
const int Maxn=2000;
const int Maxm=100000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n,m,s,t;
int p[Maxn+5];
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],val[Maxm<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
ll dis[2][Maxn+5];
bool vis[Maxn+5];
ll d[Maxn+5],d_len;
int w,h;
void dij(int s,ll *dis){
	for(int i=1;i<=n;i++){
		dis[i]=Inf;
	}
	memset(vis,0,sizeof vis);
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			if(u==0||dis[j]<dis[u]){
				u=j;
			}
		}
		if(u==0){
			break;
		}
		vis[u]=1;
		for(int j=head[u];j;j=nxt[j]){
			int v=arrive[j];
			if(dis[u]+val[j]<dis[v]){
				dis[v]=dis[u]+val[j];
			}
		}
	}
	d_len=0;
	for(int i=1;i<=n;i++){
		d[++d_len]=dis[i];
	}
	sort(d+1,d+1+d_len);
	d_len=unique(d+1,d+1+d_len)-d-1;
	for(int i=1;i<=n;i++){
		dis[i]=lower_bound(d+1,d+1+d_len,dis[i])-d;
	}
	h=d_len;
}
ll sum[Maxn+5][Maxn+5];
int cnt[Maxn+5][Maxn+5];
ll f[2][Maxn+5][Maxn+5];
int nxt_x[Maxn+5][Maxn+5],nxt_y[Maxn+5][Maxn+5];
int main(){
	read(n),read(m);
	read(s),read(t);
	for(int i=1;i<=n;i++){
		read(p[i]);
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u),read(v),read(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dij(s,dis[0]);
	w=h;
	dij(t,dis[1]);
	for(int i=1;i<=n;i++){
		sum[dis[0][i]][dis[1][i]]+=p[i];
		cnt[dis[0][i]][dis[1][i]]++;
	}
	for(int i=w;i>0;i--){
		for(int j=h;j>0;j--){
			sum[i][j]+=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
			nxt_x[i][j]=min(i<w?nxt_x[i+1][j]:w,j<h?nxt_x[i][j+1]:w);
			nxt_y[i][j]=min(i<w?nxt_y[i+1][j]:h,j<h?nxt_y[i][j+1]:h);
			if(cnt[i][j]){
				nxt_x[i][j]=i;
				nxt_y[i][j]=j;
			}
		}
	}
	for(int i=w;i>0;i--){
		for(int j=h;j>0;j--){
			f[0][i][j]=sum[i][j]-f[1][nxt_x[i][j]+1][j];
			f[1][i][j]=sum[i][j]-f[0][i][nxt_y[i][j]+1];
			if(i==1&&j==1){
				continue;
			}
			f[0][i][j]=min(f[0][i][j],f[0][i][j+1]);
			f[1][i][j]=min(f[1][i][j],f[1][i+1][j]);
		}
	}
	ll Tavas=f[0][1][1],Nafas=sum[1][1]-Tavas;
	if(Tavas==Nafas){
		puts("Flowers");
	}
	else if(Tavas>Nafas){
		puts("Break a heart");
	}
	else{
		puts("Cry");
	}
	return 0;
}