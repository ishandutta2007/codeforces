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
#define int long long
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
const int INF=1e15;
namespace flow{
	int n;
	int s,t;
	int head[1050],nxt[6010],to[6010],w[6010],tot,tmp[1050];
	int dep[1050],gap[1050];
	void add(int x,int y,int z){
		nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
		nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0;
	}
	void clear(int N){
		for(int i=2;i<=tot;++i) to[tot]=w[tot]=nxt[tot]=0;
		n=N,s=N-1,t=N;
		for(int i=0;i<=N;++i) head[i]=0,dep[i]=gap[i]=0;tot=1;
	}
	bool bfs(){
		queue<int>Q;
		dep[t]=gap[1]=1;
		Q.push(t);
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			for(int i=head[x];i;i=nxt[i]){
				int v=to[i];
				if(!dep[v]){
					dep[v]=dep[x]+1;++gap[dep[v]];Q.push(v);
				}
			}
		}
		return dep[s]!=0;
	}
	int dfs(int x,int mf){
		if(x==t) return mf;
		int sum=0;
		for(int &i=tmp[x];i;i=nxt[i]){
			int v=to[i];
			if(dep[v]+1==dep[x]&&w[i]>0){
				int d=dfs(v,min(mf,w[i]));
				w[i]-=d;w[i^1]+=d;sum+=d;mf-=d;
				if(mf==0) return sum;
			}
		}
		if(--gap[dep[x]]==0) dep[s]=n+2;
		++gap[++dep[x]];
		tmp[x]=head[x];
		return sum;
	}
	int flow(){
		int mxf=0;
		if(!bfs()) return 0;
		for(int i=1;i<=n;++i) tmp[i]=head[i];
		while(dep[s]<=n){
			mxf+=dfs(s,INF);
		}
		return mxf;
	}
	vector<int>mincut(){
		vector<int>res(n+1,0);
		res[s]=1;queue<int>Q;Q.push(s);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			for(int i=head[u];i;i=nxt[i]){
				if(w[i]&&!res[to[i]]){
					res[to[i]]=1;Q.push(to[i]);
				}
			}
		}
		return res;
	}
}
int n,m;
int a[1010];
vector<int>vec[1010];
int ans[1010];
int Id[1010];
void solve(int l,int r,vector<int>&V){
	if(!V.size()) return ;
	if(l==r){
		for(int i:V) ans[i]=l;return ;
	}
	flow::clear(V.size()+3);
	for(int i=0;i<V.size();++i){
		Id[V[i]]=i+1;
	}
	int mid=l+r>>1;
	vector<int>L,R;
	for(int i=0;i<V.size();++i){
		int w=(a[V[i]]<=mid?-1:1);
		if(w>0) flow::add(flow::s,i+1,w);
		else if(w<0) flow::add(i+1,flow::t,-w);
	}
	for(int i=0;i<V.size();++i){
		for(int j:vec[V[i]]) if(Id[j]){
			flow::add(i+1,Id[j],INF);
		}
	}
	int f=flow::flow();
	vector<int>re=flow::mincut();
	for(int i=0;i<V.size();++i){
		if(re[i+1]) R.pb(V[i]);else L.pb(V[i]);
	}
	for(int i=0;i<V.size();++i){
		Id[V[i]]=0;
	}
	solve(l,mid,L);solve(mid+1,r,R);
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();vec[u].pb(v);
	}
	vector<int>all;
	for(int i=1;i<=n;++i) all.pb(i);
	solve(1,1e10,all);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
}