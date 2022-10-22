#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=1e9+7;
int n,m;
vector<PII>vec[100010];
struct xxj{
	int p[8];
	bool insert(int x){
		for(int i=4;i>=0;--i){
			if(x&(1<<i)){
				if(!p[i]){
					p[i]=x;
					for(int j=0;j<i;++j) if(p[j]&&(p[i]&(1<<j))) p[i]^=p[j];
					for(int j=i+1;j<=4;++j){
						if(p[j]&(1<<i)) p[j]^=p[i];
					}
					return 1;
				}
				else x^=p[i];
			}
		}
		return 0;
	}
	int hsh(){
		return p[0]|p[1]<<1|p[2]<<3|p[3]<<6|p[4]<<10;
	}
	friend bool operator <(xxj x,xxj y){
		return x.hsh()<y.hsh();
	}
	xxj(){
		memset(p,0,sizeof(p));
	}
}lst[410],T;
int dp[410][2];
int trans[410][410];
int cnt;
map<xxj,int>Map;
map<int,int>Ma;
void dfs(xxj tmp){
	int hsh=tmp.hsh();
	if(Ma.count(hsh)) return (void)(Map[tmp]=Ma[hsh]);
	else{
		Ma[hsh]=Map[tmp]=++cnt;
		lst[cnt]=tmp;
	}
	for(int i=1;i<32;++i){
		xxj to=tmp;
		if(to.insert(i)) dfs(to);
	}
}
int merge(int x,int y){
	xxj t=lst[x],p=lst[y];
	for(int i=5;i>=0;--i) if(p.p[i]) if(!t.insert(p.p[i])) return -1;
	return Map[t];
}
void gettrans(){
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=cnt;++j){
			trans[i][j]=merge(i,j);
		}
	}
}
int con[100010],cir[100010];
int ter[100010];
bool vis[100010];
int val[100010],dis[100010];
int dep[100010];
int dfs2(int x,int fa,int d){
	dis[x]=d;dep[x]=dep[fa]+1;
	for(auto i:vec[x]){
		int v=i.fi;
		if(v==fa||v==1) continue ;
		if(dep[v]&&dep[v]<dep[x]){
			if(!T.insert(dis[x]^dis[v]^i.se)) return -1;
		}
		else if(!dep[v]){
			if(dfs2(v,x,d^i.se)==-1) return -1;
		} 
	}
	return 1;
}
void bfs(){
	memset(con,-1,sizeof(con));
	for(auto i:vec[1]) con[i.fi]=i.se;
	for(auto i:vec[1]){
		int v=i.fi;
		for(auto j:vec[v]){
			int t=j.fi;
			if(con[t]!=-1) {
				ter[t]=v,ter[v]=t;cir[t]=cir[v]=con[t]^con[v]^j.se;
			}
		}
	}
	for(auto i:vec[1]){
		int v=i.fi;
		memset(T.p,0,sizeof(T.p));
		if(vis[v]) continue ;
		if(dfs2(v,1,0)==-1) val[v]=-1;
		else val[v]=Map[T];
		vis[ter[v]]=1;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),c=read();
		vec[u].ep(v,c);vec[v].ep(u,c);
	}
	dfs(xxj());
	gettrans(); 
	bfs();
	memset(T.p,0,sizeof(T.p));
	dp[Map[T]][0]=1;
	bool flag=0;
	for(auto i:vec[1]){
		flag^=1;
		int v=i.fi;
		for(int j=1;j<=cnt;++j) dp[j][flag]=dp[j][flag^1];
		if(vis[v]) continue ;
		vis[v]=1;
		if(val[v]==-1) continue ;
		if(!ter[v]){
			for(int j=1;j<=cnt;++j){
				if(trans[j][val[v]]!=-1) (dp[trans[j][val[v]]][flag]+=dp[j][flag^1])%=mod;
			}
		}
		else{
			vis[ter[v]]=1;
			xxj tmp=lst[val[v]];
			bool can=tmp.insert(cir[v]);
			int t=Map[tmp];
			for(int j=1;j<=cnt;++j){
				if(trans[j][val[v]]!=-1) (dp[trans[j][val[v]]][flag]+=2ll*dp[j][flag^1]%mod)%=mod;
				if(can&&trans[j][t]!=-1) (dp[trans[j][t]][flag]+=dp[j][flag^1])%=mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;++i) (ans+=dp[i][flag])%=mod;
	printf("%d\n",ans);
}