#include<bits/stdc++.h>
const int N=2003;
using namespace std;
typedef long long ll;
int n,m,S,T,a[N],h[N][N],
u,v,w,mp[N][N],la[N],lb;
bool vis[N];
ll da[N],db[N],ls[N],fa[N][N],fb[N][N],g[N][N],tp;
inline void dij(int S,ll*d){
	for(int i=0;i<=n;i++)
	d[i]=1e18,vis[i]=0;
	d[S]=0;
	for(int i=1;i<=n;i++){
		u=0;
		for(int j=1;j<=n;j++)
		if(!vis[j]&&d[j]<d[u])u=j;
		vis[u]=1;ls[i-1]=d[u];
		for(int j=1;j<=n;j++)
		if(mp[u][j]<0x3f3f3f3f)
		d[j]=min(d[j],d[u]+mp[u][j]);
	}
	int t;
	sort(ls,ls+n);t=unique(ls,ls+n)-ls;
	for(int i=1;i<=n;i++)
	d[i]=lower_bound(ls,ls+t,d[i])-ls;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	memset(mp,0x3f,sizeof mp);
	for(;m--;)
	scanf("%d%d%d",&u,&v,&w),
	mp[u][v]=min(mp[u][v],w),
	mp[v][u]=min(mp[v][u],w);
	dij(S,da),dij(T,db);
	for(int i=1;i<=n;i++)
	g[da[i]][db[i]]+=a[i],
	//cerr<<"ins "<<da[i]<<','<<db[i]<<endl,
	h[da[i]][db[i]]=1;
	for(int i=0;i<=n;i++)
	la[i]=n;
	for(int i=n-1;~i;i--){
		lb=n;
		for(int j=n-1;~j;j--){
			g[i][j]+=g[i][j+1]+g[i+1][j]-g[i+1][j+1];
			tp=g[i][j];
			h[i][j]+=h[i][j+1]+h[i+1][j]-h[i+1][j+1];
			if(h[i][j]>h[i+1][j])la[j]=i+1;
			if(h[i][j]>h[i][j+1])lb=j+1;
			fa[i][j]=fb[la[j]][j]+tp;
			fb[i][j]=fa[i][lb]-tp;
			//cerr<<"("<<i<<','<<j<<")"<<fa[i][j]<<'&'<<fb[i][j]<<endl
			//<<la[j]<<'/'<<lb<<endl;
			if(i||j)
			fa[i][j]=min(fa[i][j]+tp,fa[i][j+1]),
			fb[i][j]=max(fb[i][j]-tp,fb[i+1][j]);
		}
	}
	puts(fa[0][0]?fa[0][0]>0?"Break a heart":"Cry":"Flowers");
}