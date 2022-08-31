#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 205
using namespace std;
typedef long long ll;
struct poi{
	int x,y;
	poi operator-(poi p){return (poi){x-p.x,y-p.y};}
	ll operator*(poi p){return 1ll*x*p.y-1ll*y*p.x;}
}A[N],a[N];
bool cmp(poi x,poi y){return x*y>0;}
bool turn(int x,int y,int z){return (a[y]-a[x])*(a[z]-a[y])>0;}
int b[N<<1],v[N*N],f[N*N],tot;
int q[N][N],l[N],r[N];
int n,nn,m;
ll d[N][N][55],w[55],ans;
void add(int x,int y){v[++tot]=y,f[tot]=b[x],b[x]=tot;}
void link(int x,int y){
	for(;l[x]<r[x]&&turn(q[x][l[x]],x,y);++l[x])link(q[x][l[x]],y);
	add(x+nn,y);add(y,x);q[y][r[y]++]=x;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d%d",&A[i].x,&A[i].y);ans=0;
	rep(i,n){
		nn=0;
		rep(j,n)if(i!=j&&A[i].x<=A[j].x)a[++nn]=A[j]-A[i];
		sort(a+1,a+nn+1,cmp);
		memset(b,0,sizeof b);tot=0;
		memset(l,0,sizeof l);memset(r,0,sizeof r);
		rep(j,nn-1)link(j,j+1);
		rep(j,nn)for(int k=b[j+nn];k;k=f[k])for(int p=0;p<=m;++p)d[j][v[k]][p]=0;
		for(int j=nn;j;--j){
			memset(w,0,sizeof w);
			int k=b[j+nn];
			for(int p=b[j];p;p=f[p]){
				d[v[p]][j][0]=0;
				d[v[p]][j][1]=a[v[p]]*a[j];
				for(int u=2;u<=m;++u)d[v[p]][j][u]=w[u-1]>0?w[u-1]+a[v[p]]*a[j]:0;
				for(;k&&turn(v[p],j,v[k]);k=f[k])
					rep(u,m)if(d[j][v[k]][u-1]>w[u-1])
						w[u-1]=d[j][v[k]][u-1],d[v[p]][j][u]=w[u-1]+a[v[p]]*a[j];
			}
		}
		rep(j,nn)for(int k=b[j+nn];k;k=f[k])ans=max(ans,d[j][v[k]][m-2]);
	}
	printf("%lld",ans>>1);puts(ans&1?".50":".00");
	return 0;
}