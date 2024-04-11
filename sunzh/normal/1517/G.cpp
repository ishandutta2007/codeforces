#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n;
const int inf=0x3f3f3f3f3f3f3fll;
struct node{
	int x,y,w;
}T[2010];
map<PII,int>Map;
map<PII,int>idx;
int cnt,s,t;
int tot=1;
int head[2010],nxt[20010],to[20010],w[20010];
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
}
int dep[2010],gap[2010];
bool bfs(){
	queue<int>Q;
	Q.push(t);dep[t]=gap[1]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(!dep[v]){
				dep[v]=dep[u]+1;++gap[dep[v]];
				Q.push(v);
			}
		}
	}
	return dep[s]?1:0;
}
int dfs(int x,int mf){
	if(x==t) return mf;
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(dep[v]+1==dep[x]&&w[i]){
			int d=dfs(v,min(mf,w[i]));
			sum+=d;mf-=d;w[i]-=d,w[i^1]+=d;
			if(mf==0) return sum;
		}
	}
	if(--gap[dep[x]]==0) dep[s]=t+4;
	++gap[++dep[x]];
	return sum;
}
int ISAP(){
	if(!bfs()) return 0;
	int ans=0;
	while(dep[s]<=t+3){
		ans+=dfs(s,inf);
	}
	return ans;
}
signed main(){
	n=read();
	long long sum=0;
	for(int i=1;i<=n;++i) {
		int x=read(),y=read(),w=read();
		Map[mp(x,y)]+=w;
		if(!idx.count(mp(x,y))) idx[mp(x,y)]=++cnt;
		sum+=w;
	}
	s=0,t=cnt+cnt+1;
	for(auto it:Map){
		PII t=it.fi;
		int id=idx[t]+cnt;
		add(idx[t],id,it.se);
		add(id,idx[t],0);
		PII v;
		if(t.fi%2==0){
			if(t.se%2==0){
				v=t;v.se--;
				if(Map.count(v)){
					add(id,idx[v],inf);
					add(idx[v],id,0);
				}
				v=t,v.se++;
				if(Map.count(v)){
					add(id,idx[v],inf);
					add(idx[v],id,0);
				}
			}
			else{
				v=t;v.fi++;
				if(Map.count(v)){
					add(id,idx[v],inf);
					add(idx[v],id,0);
				}
				v=t;v.fi--;
				if(Map.count(v)){
					add(id,idx[v],inf);
					add(idx[v],id,0);
				}
			}
		}
		else{
			if(t.se%2==0){
				add(s,idx[t],inf);add(idx[t],s,0);
				v=t;v.fi--;
				if(Map.count(v)){
					add(id,idx[v],inf);
					add(idx[v],id,0);
				}
				v=t;v.fi++;
				if(Map.count(v)){
					add(id,idx[v],inf);
					add(idx[v],id,0);
				}
			}
			else{
				add(id,cnt+cnt+1,inf);add(cnt+cnt+1,id,0);
			}
		}
	}
	printf("%lld\n",sum-ISAP());
	return 0;
}