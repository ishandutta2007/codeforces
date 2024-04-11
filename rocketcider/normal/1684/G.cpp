#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3fll;
struct edge{
	int to;
	ll f;
};
vector<edge>e;
vector<int>hd[maxn];
inline void addedge(int fr,int to,ll f){
	hd[fr].push_back(e.size());
	e.push_back({to,f});
	hd[to].push_back(e.size());
	e.push_back({fr,0});
}
int dep[maxn],s,t;
inline bool bfs(){
	memset(dep,0,sizeof dep);
	dep[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size()){
		ri now=q.front();q.pop();
		for(ri i=0;i<hd[now].size();++i){
			ri id=hd[now][i],nxt=e[id].to;
			if(e[id].f>0&&!dep[nxt])dep[nxt]=dep[now]+1,q.push(nxt);
		}
	}
	return dep[t];
}
ll dfs(int now,ll lim){
	if(now==t)return lim;
	ll sum=0;
	for(ri i=0;i<hd[now].size();++i){
		ri id=hd[now][i],nxt=e[id].to;
		if(e[id].f>0&&dep[now]+1==dep[nxt]){
			ll flow=dfs(nxt,min(lim-sum,e[id].f));
			e[id].f-=flow,e[id^1].f+=flow;
			sum+=flow;
			if(lim==sum)break;
		}
	}
	if(!sum)dep[now]=0;
	return sum;
}
inline ll dinic(){
	ll ret=0;
	while(bfs())ret+=dfs(s,inf);
	return ret;
}
int m,n,t_case;
bool vis[maxn];
signed main(){
	scanf("%lld%lld",&n,&m);
	s=n+1,t=n+2;
	e.clear();
	for(ri i=1;i<=t;++i)hd[i].clear();
	vector<int>a,b;
	for(ri i=1,x;i<=n;++i){
		scanf("%lld",&x);
		if(x*3<=m)b.push_back(x);
		else a.push_back(x);
	}
	for(ri i=0;i<a.size();++i)addedge(s,i+1,1);
	for(ri i=0;i<b.size();++i)addedge(i+1+a.size(),t,1);
	for(ri i=0;i<a.size();++i)
		for(ri j=0;j<b.size();++j)
			if(a[i]%b[j]==0&&a[i]*2+b[j]<=m)
				addedge(i+1,j+1+a.size(),1);
	if(dinic()!=a.size()){
		puts("-1");
		return 0;
	}
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	vector<pii>ans;
	for(ri i=0;i<a.size();++i)
		for(ri j:hd[i+1])
			if(e[j^1].f){
				ri nxt=e[j].to;
				ans.emplace_back(a[i]*2+b[nxt-a.size()-1],a[i]+b[nxt-a.size()-1]);
				vis[nxt-a.size()-1]=true;
			}
	for(ri i=0;i<b.size();++i)
		if(!vis[i])
			ans.emplace_back(b[i]*2,b[i]*3);
	printf("%lld\n",(int)ans.size());
	for(const pii &i:ans)printf("%lld %lld\n",i.fi,i.se);
	return 0;
}