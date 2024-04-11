#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define mn 105
int n,m;
int x[mn],y[mn];
int X[mn],Y[mn],T[mn];
int td[1<<14][15],tp[1<<14][mn];
int f[1<<14][mn],g[1<<14][mn];
const int inf=1e17;
int dis(int x,int y,int X,int Y){
	return abs(x-X)+abs(y-Y);
}
int id[mn];
bool cmp(int a,int b){return T[a]<T[b];}
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		x[i]=read(),y[i]=read();
	}
	for(int i=1;i<=m;++i){
		X[i]=read(),Y[i]=read(),T[i]=read();
		id[i]=i;
	}
	sort(id+1,id+1+m,cmp);
	for(int i=0;i<(1<<n);++i){
		for(int j=1;j<=n;++j){
			int res=inf;		
			for(int k=0;k<n;++k)
				if((i>>k)&1)
					res=min(res,dis(x[k+1],y[k+1],x[j],y[j]));
			td[i][j]=res;
		}
		for(int j=1;j<=m;++j){
			int res=inf;		
			for(int k=0;k<n;++k)
				if((i>>k)&1)
					res=min(res,dis(x[k+1],y[k+1],X[j],Y[j]));
			tp[i][j]=res;
		}
	}
	memset(f,0x3f,sizeof(f));
	memset(g,-0x3f,sizeof(g));
	for(int i=1;i<=n;++i)f[1<<i-1][0]=0;
	for(int i=1;i<=m;++i){
		g[0][i]=1;
	}
	int ans=0;
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<=m;++j){
			if(f[i][j]>inf)continue;
			for(int k=0;k<n;++k)
				if(!((i>>k)&1))f[i|(1<<k)][j]=min(f[i|(1<<k)][j],f[i][j]+td[i][k+1]);
			for(int k=1;k<=m;++k){
				if(f[i][j]+tp[i][k]<=T[k])
					g[i][k]=max(g[i][k],j+1);
			}
		}
		for(int J=1;J<=m;++J){
			int j=id[J];
			if(g[i][j]<0)continue;
			ans=max(ans,g[i][j]);
			for(int k=0;k<n;++k)
				if(!((i>>k)&1)&&g[i][j]>=0)
					f[i|(1<<k)][g[i][j]]=min(f[i|(1<<k)][g[i][j]],T[j]+min(dis(X[j],Y[j],x[k+1],y[k+1]),td[i][k+1]));
			for(int K=J+1;K<=m;++K){
				int k=id[K];
				int d=min(dis(X[j],Y[j],X[k],Y[k]),tp[i][k]);
				if(T[j]+d>T[k])continue;	
				g[i][k]=max(g[i][k],g[i][j]+1);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}