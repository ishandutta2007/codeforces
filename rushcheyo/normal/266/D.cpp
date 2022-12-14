#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,g[205][205],d[205][205],x[205],ans;
void solve(int u,int v){
	int ma=0;
	for(int i=n;i;i--){
		int p=g[u][v]+ma-d[u][x[i]];
		if(p<0)p=0;
		if(p>g[u][v]*2)p=g[u][v]*2;
		ans=min(ans,max(p+d[u][x[i]]*2,g[u][v]*2-p+ma*2));
		ma=max(ma,d[x[i]][v]);
	}
	ans=min(ans,ma*2);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)g[i][j]=INF;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		scanf("%d",g[a]+b);
		g[b][a]=g[a][b];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=g[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	ans=INF;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)x[j]=j;
		sort(x+1,x+1+n,[=](int a,int b){return d[i][a]<d[i][b];});
		for(int j=i+1;j<=n;j++)
			if(g[i][j]!=INF)solve(i,j);
	}
	printf("%d",ans>>1);
	if(ans&1)printf(".5");
	puts("");
}