#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define int long long
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
int n;
const int inf=3e8,INF=1e9;
int tot=1;
int head[1010],nxt[200010],to[2000010],flow[2000010];
void add(int x,int y,int z){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,flow[tot]=z;
}
int s,t;
int dep[1010],gap[1010];
bool bfs(int s,int t){
	queue<int>Q;
	Q.push(t);
	dep[t]=gap[1]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int i=head[u];i;i=nxt[i]){
			if(!dep[to[i]]){
				dep[to[i]]=dep[u]+1;
				gap[dep[to[i]]]++;
				Q.push(to[i]);
			}
		}
	}
	return dep[s]!=0;
}
int dfs(int x,int maxf){
	if(x==t) return maxf;
	int sum=0;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(dep[v]+1==dep[x]){
			int d=dfs(v,min(maxf,flow[i]));
			sum+=d,maxf-=d;
			flow[i]-=d,flow[i^1]+=d;
			if(!maxf) return sum;
		}
	}
	if(--gap[dep[x]]==0) dep[s]=t+1;
	++gap[++dep[x]];
	return sum;
}
int ISAP(int s,int t){
	int maxf=0;
	if(!bfs(s,t)) return 0;
	while(dep[s]<=t) maxf+=dfs(s,INF*INF);
	return maxf;
}
signed main(){
	n=read();
	s=0,t=n+n+1;
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			int x=read();
			add(i,x+n,INF);
			add(x+n,i,0);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=read();
		add(s,i,inf-x);
		add(i,s,0);
		add(i+n,t,inf);
		add(t,i+n,0);
		ans+=inf-x;
	}
//	printf("%lld\n",ISAP(s,t));
	printf("%lld\n",ISAP(s,t)-ans);
	return 0;
}