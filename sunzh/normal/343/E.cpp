#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
struct edge{
	int u,v,w;
}e[1010];
namespace FLOW{
	vector<PII>tre[210];
	int head[210],nxt[2010],to[2010],w[2010],tot;
	int dep[210],gap[210],tmp[210];
	int d[210];
	int s,t;
	void add(int x,int y,int z){
		nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
		nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=z;
	}
	bool bfs(int s,int t){
		queue<int>Q;Q.push(t);dep[t]=gap[1]=1;
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int i=head[u];i;i=nxt[i]){
				// printf("u:%d,i:%d,to:%d\n",u,i,to[i]);
				if(!dep[to[i]]){
					dep[to[i]]=dep[u]+1;
					++gap[dep[to[i]]];
					Q.push(to[i]);
				}
			}
		}
		return dep[s]!=0;
	}
	int dfs(int x,int mxf){
		// printf("x:%d,mxf:%d\n",x,mxf);
		if(x==t) return mxf;
		int sum=0;
		for(int &i=tmp[x];i;i=nxt[i]){
			int v=to[i];
			if(w[i]&&dep[v]+1==dep[x]){
				int d=dfs(v,min(w[i],mxf));
				sum+=d;mxf-=d;w[i]-=d;w[i^1]+=d;
				if(mxf==0) return sum;
			}
		}
		if(!--gap[dep[x]]) dep[s]=n+10;
		++gap[++dep[x]];
		tmp[x]=head[x];
		return sum;
	}
	int ISAP(int s,int t){
		if(!bfs(s,t)) return 0;
		// printf("bfs\n");
		int mxf=0;
		while(dep[s]<=n+2){
			memcpy(tmp,head,sizeof(head));
			mxf+=dfs(s,0x3f3f3f3f);
			// printf("%d\n",mxf);
		}
		return mxf;
	}
	void Bfs(int s){
		d[s]=1;queue<int>Q;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int i=head[u];i;i=nxt[i]){
				if(w[i]&&!d[to[i]]){
					d[to[i]]=d[u]+1;Q.push(to[i]);
				}
			}
		}
	}
	void rebuild(){
		memset(head,0,sizeof(head));tot=1;
		for(int i=1;i<=m;++i) add(e[i].u,e[i].v,e[i].w);
		memset(d,0,sizeof(d));
		memset(dep,0,sizeof(dep));
		memset(gap,0,sizeof(gap));
	}
}
using namespace FLOW;
void build(vector<int>ve){
	// for(int i:ve) printf("%d ",i);printf("\n");
	if(ve.size()==1) return ;
	s=ve[0],t=ve[1];
	rebuild();
	// printf("build\n");
	int f=ISAP(s,t);
	// printf("%d %d,%d\n",s,t,f);
	// printf("f:%d\n",f);
	tre[s].pb(mp(t,f));
	tre[t].pb(mp(s,f));
	Bfs(s);
	vector<int>ls,rs;
	for(int i:ve){
		if(d[i]) ls.pb(i);else rs.pb(i);
	}
	build(ls);build(rs);
}
bool in[210];
vector<int>Ans;
long long ans=0;
bool Vis[210];
vector<int>Bfs(int x,int y){
	queue<int>Q;
	memset(Vis,0,sizeof(Vis));
	Q.push(x);
	Vis[x]=1;
	vector<int>ret;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		ret.pb(u);
		for(PII i:tre[u]){
			int v=i.fi;
			if(v!=y&&in[v]&&!Vis[v]){
				Vis[v]=1;Q.push(v);
			}
		}
	}
	return ret;
}
void solve(vector<int>st){
	if(st.size()==1){
		Ans.pb(st[0]);return ;
	}
	memset(in,0,sizeof(in));
	for(int i:st) in[i]=1;
	PII mied;
	int mn=0x7f7f7f7f;
	for(int i:st){
		for(PII j:tre[i]) if(in[j.fi]) {
			if(j.se<mn) mn=j.se,mied=mp(i,j.fi);
		}
	}
	vector<int>ls=Bfs(mied.fi,mied.se),rs=Bfs(mied.se,mied.fi);
	solve(ls);
	ans+=mn;
	solve(rs);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	vector<int>all;
	for(int i=1;i<=n;++i) all.pb(i);
	build(all);
	solve(all);
	printf("%lld\n",ans);
	for(int i:Ans) printf("%d ",i);
}