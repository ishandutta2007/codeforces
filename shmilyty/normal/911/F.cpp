#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct edge{
	int to,nxt;
}e[N<<1];
int n,dis[N],head[N],cnt=0,u,v,fa[N];
long long ans=0;
bool on[N];
vector<pair<int,int>>s;
void dfs(int now){
	for(int i=head[now];i;i=e[i].nxt)
	if(!~dis[e[i].to]){
		dis[e[i].to]=dis[now]+1;
		dfs(e[i].to);
	}
}
void dfs2(int now){
	for(int i=head[now];i;i=e[i].nxt)
	if(dis[e[i].to]>dis[now]){
		fa[e[i].to]=now;
		dfs2(e[i].to);
		on[now]=on[now]||on[e[i].to];
	}
}
inline void dfs3(int now,int rt){
	for(int i=head[now];i;i=e[i].nxt)
	if(dis[e[i].to]>dis[now])dfs3(e[i].to,on[e[i].to]?e[i].to:rt);
	if(!on[now]){
		if(dis[now]>dis[now]+dis[v]-(dis[rt]<<1)){
			ans+=dis[now];
			s.push_back(make_pair(u,now));
		}else{
			ans+=dis[now]+dis[v]-(dis[rt]<<1);
			s.push_back(make_pair(v,now));
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		e[++cnt]=(edge){v,head[u]};
		head[u]=cnt;
		e[++cnt]=(edge){u,head[v]};
		head[v]=cnt;
	}
	memset(dis,-1,sizeof dis);
	dis[1]=0;
	dfs(1);
	u=1;
	for(int i=2;i<=n;++i)
	if(dis[i]>dis[u])u=i;
	memset(dis,-1,sizeof dis);
	dis[u]=0;
	dfs(u);
	v=u;
	for(int i=1;i<=n;++i)
	if(dis[v]<dis[i])v=i;
	on[v]=true;
	dfs2(u);dfs3(u,u);
	for(;u!=v;v=fa[v])ans+=dis[v],s.push_back(make_pair(u,v));
	printf("%lld\n",ans);
	for(auto i:s)printf("%d %d %d\n",i.first,i.second,i.second);
	return 0;
}