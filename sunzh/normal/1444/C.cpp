#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m,k;
int belong[500010];
PII fr[500010];
vector<int>G[500010],T[5000010],vec,st[500010]; 
map<PII,vector<int> >Map;
map<PII,bool> used;
int col[5000010];
int idx;
int id[500010];
bool ok[500010];
bool dfs(int x){
	id[x]=idx-col[x];
	for(int v:G[x]){
		if(belong[v]!=belong[x]) continue ;
		if(col[v]==-1){
			col[v]=col[x]^1;
			if(!dfs(v)) return 0;
		}
		else{
			if(col[v]==col[x]) return 0;
		}
	}
	return 1;
}
bool dfs2(int x){
	for(int v:T[x]){
		if(col[v]!=-1){
			if(col[x]==col[v]) return 0;
		}
		else{
			col[v]=col[x]^1;
			if(!dfs2(v)) return 0;
		}
	}
	return 1;
}
bool check(){
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int las=-1;
	for(int u:vec){
		if(las==(u^1)){
			T[u].pb(las);T[las].pb(u);
		}
		las=u;
	}
//	for(int u:vec){
//		printf("u:%d ",u);
//		for(int v:T[u]) printf("%d ",v);
//		printf("\n");
//	}
	for(int u:vec) col[u]=-1;
	for(int u:vec){
		if(col[u]!=-1) continue ;
		col[u]=0;
		if(!dfs2(u)){
//			printf("ou%d\n",u);
		return 1;
		}
	}
	return 0;
}
void clear(){
	for(int i:vec) T[i].clear();
	vec.clear();
}
int main(){
	idx=1;
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i) ok[i]=1;
	for(int i=1;i<=n;++i){
		belong[i]=read();
		st[belong[i]].pb(i);
	} 
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
		if(belong[u]>belong[v]) swap(u,v);
		fr[i].fi=u,fr[i].se=v;
		Map[mp(belong[u],belong[v])].pb(i);
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=k;++i){
		for(int v:st[i]){
			if(col[v]==-1){
			col[v]=0;
			idx+=2;
			if(!dfs(v)){
				ok[i]=0;break ;
			} 
		}
		}
	}
	int cnt=0;
	for(int i=1;i<=k;++i) if(ok[i]) ++cnt;
	long long ans=1ll*cnt*(cnt-1)>>1;
//	printf("%lld\n",ans);
	for(int i=1;i<=m;++i){
		if(!ok[belong[fr[i].fi]]) continue ;
		if(!ok[belong[fr[i].se]]) continue ;
		PII tmp=mp(belong[fr[i].fi],belong[fr[i].se]);
		if(tmp.fi==tmp.se) continue ;
		if(used[tmp]) continue ;
//		printf("%d %d\n",tmp.fi,tmp.se);
		used[tmp]=1;
		clear();
		for(auto v:Map[tmp]){
			T[id[fr[v].fi]].pb(id[fr[v].se]);
			T[id[fr[v].se]].pb(id[fr[v].fi]);
			vec.pb(id[fr[v].fi]);vec.pb(id[fr[v].se]);
		}
		if(check()) --ans;
	}
	printf("%lld\n",ans);
//	for(int i=1;i<=n;++i) printf("%d ",id[i]);
}