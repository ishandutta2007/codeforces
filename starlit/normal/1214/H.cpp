#include<bits/stdc++.h>
#define rep for(int s,i=lk[x];i;i=hd[i])\
if((s=to[i])^y)
const int N=200005;
using namespace std;
int n,k,to[N<<1],hd[N<<1],lk[N],cnt,
mx[N],dep[N],rt,bot,ans[N];
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}int u,v;
void dfs(int x,int y=0){
	dep[x]=dep[y]+1,mx[x]=x;
	rep{
		dfs(s,x);
		if(dep[mx[s]]>dep[mx[x]])
		mx[x]=mx[s];
	}
}
void dfss(int x,int y=0,int dis=0){
	if(mx[x]!=bot&&mx[y]==bot)
	dis=dep[y];
	//cerr<<'('<<x<<','<<y<<','<<dis<<")\n";
	if(mx[x]!=bot&&dis<<1<=dep[bot])
	(ans[x]=ans[y]-1)?0:ans[x]=k;
	else (ans[x]=ans[y]+1)>k?ans[x]=1:0;
	int fi=0,se=0;
	rep{
		dfss(s,x,dis);
		if(dep[mx[s]]>fi)se=fi,fi=dep[mx[s]];
		else if(dep[mx[s]]>se)se=dep[mx[s]];
	}
	if(fi&&se&&y&&k>2){
		if(mx[x]!=bot&&dis<<1<=dep[bot])
		dis=dep[x]+dep[bot]-2*dis;
		else dis=dep[x]-1;
		fi-=dep[x],se-=dep[x];
		//cerr<<"chk "<<x<<":"<<fi<<' '<<se<<' '<<dis<<endl;
		if(fi+dis>=k-1&&se+dis>=k-1&&fi+se>=k-1)
		puts("No"),exit(0);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	scanf("%d%d",&u,&v),
	add(u,v),add(v,u);
	dfs(1),dfs(rt=mx[1]);
	//cerr<<"rt:"<<rt<<endl;
	bot=mx[rt],dfss(rt);
	puts("Yes");
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
}