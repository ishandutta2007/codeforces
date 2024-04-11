#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int b[N],v[N<<1],f[N<<1],tot;
int a[N];
int n,m,k,s;
int x,y;
int dis[N][105],q[N],L,R;
void add(int x,int y){v[++tot]=y,f[tot]=b[x],b[x]=tot;}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	rep(i,n)scanf("%d",a+i);
	rep(i,m)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	rep(cur,k){
		rep(i,n)dis[i][cur]=inf;L=R=0;
		rep(i,n)if(a[i]==cur)q[++R]=i,dis[i][cur]=0;
		while(L!=R){
			x=q[++L];
			for(int i=b[x];i;i=f[i])
				if(dis[v[i]][cur]==inf)dis[q[++R]=v[i]][cur]=dis[x][cur]+1;
		}
	}
	rep(i,n){
		sort(dis[i]+1,dis[i]+k+1);
		int ans=0;
		rep(j,s)ans+=dis[i][j];
		printf("%d%c",ans," \n"[i==n]);
	}
	//system("pause");
	return 0;
}