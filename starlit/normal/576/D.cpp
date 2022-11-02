#include<bits/stdc++.h>
const int N=153,L=32;
using namespace std;
int n,m,lim,dis[N],ans,q[N],t;
bool f[L][N][N],re[N],rf[N],mp[N][N];
void ins(int d,int u,int v){
	if(d==L||f[d][u][v])return;
	f[d][u][v]=1;
	//cerr<<"lit "<<d<<"("<<u<<','<<v<<")\n";
	for(int i=1;i<=n;i++){
		if(f[d][i][u])ins(d+1,i,v);
		if(f[d][v][i])ins(d+1,u,i);
	}
}
struct ed{int u,v,w;}e[N];
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);re[1]=1;
	for(int i=0;i<m;i++)
	scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e,e+m,[](ed a,ed b){return a.w<b.w;});
	ans=2e9;
	for(int i=0;i<m;i++){
		lim=e[i].w-(i?e[i-1].w:0);
		for(int l=0;1<<l<=lim;l++)
		if(lim>>l&1){
			//cerr<<"trans "<<l<<endl;
			for(int j=1;j<=n;j++)
			rf[j]=re[j],re[j]=0;
			for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			re[k]|=f[l][j][k]&rf[j];
		}
		mp[e[i].u][e[i].v]=1,t=0;
		for(int j=1;j<=n;j++)
		if(dis[j]=re[j])q[t++]=j;
		for(int h=0,u;h<t;){
			u=q[h++];
			for(int v=1;v<=n;v++)
			if(mp[u][v]&&!dis[v])
			dis[q[t++]=v]=dis[u]+1;
		}
		if(dis[n])ans=min(ans,dis[n]+e[i].w-1);
		ins(0,e[i].u,e[i].v);
		//cerr<<"after "<<i<<"::\n";
		//for(int j=1;j<=n;j++)cerr<<re[j]<<' ';cerr<<endl;
	}
	if(ans<2e9)printf("%d",ans);
	else puts("Impossible");
}