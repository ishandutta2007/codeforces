#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int a=0;char c=getchar();
	while(c>57 or c<48)c=getchar();
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
#define INF 1e18
int to[MN],c[MN],nxt[MN],head[MN],cnt,cur[MN];
int dep[MN],vis[MN],np[MN],a[MN];
int F[MN],siz[MN];
int n,m,S,T,N;
queue<int>Q;
void ADD(int x,int y,int z){
	++cnt;
	to[cnt]=y;
	c[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add(int x,int y,int z){
	ADD(x,y,z);
	ADD(y,x,0);
}
bool bfs(){
	while(!Q.empty())Q.pop();
	for(int i=1;i<=n+2;++i)dep[i]=0;
	Q.push(S);
	dep[S]=1;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int v=to[i];
			if(c[i]<=0)continue;
			if(!dep[v]) {
				dep[v]=dep[x]+1;
				Q.push(v);
			}
		}
	}
	return dep[T];
}
int dfs(int x,int flow){
	int rlow,use=0;
	if(x==T||!flow)return flow;
	for(int &i=cur[x];i;i=nxt[i]){
		int v=to[i];
		if(dep[v]==dep[x]+1&&c[i]>0){
			if((rlow=dfs(v,min(flow-use,c[i])))>0){
				use+=rlow;
				c[i]-=rlow;
				c[i^1]+=rlow;
				if(use==flow) return use;
			}
			else dep[v]=0;
		}
	}
	return use;               
}
int Dinic(){
	int ans=0;
	while(bfs()){
		for(int i=1;i<=n+2;++i)cur[i]=head[i];
		ans+=dfs(S,INF);
	}
	return ans;
}
int Find(int a){if(F[a]==a)return a;return F[a]=Find(F[a]);}
void Merge(int a,int b){
	int fa=Find(a),fb=Find(b);
	if(fa==fb)return;
	F[fa]=fb;
//	cerr<<"Merge: "<<fa<<" "<<fb<<" "<<siz[fa]<<" "<<siz[fb]<<endl;
	siz[fb]+=siz[fa];
}
vector<int>G[MN];
void work(int x,int rt,int lst){
	printf("%lld ",x);
	if(G[x][0]!=rt&&G[x][0]!=lst)work(G[x][0],rt,x);
	else if(G[x][1]!=rt&&G[x][1]!=lst)work(G[x][1],rt,x);
}
signed main(){
	for(int i=2;i<=20000;++i)
		if(!np[i])
		for(int j=i*i;j<=20000;j+=i)
			np[j]=1;
	cnt=1;
	n=read();
	S=n+1;T=n+2;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)
		if(a[i]&1){
			add(S,i,2);
			for(int j=1;j<=n;++j)
				if(!(a[j]&1)&&!np[a[i]+a[j]]){
//					cerr<<"edg: "<<i<<" "<<j<<endl;
					add(i,j,1);
				}
		}
	for(int i=1;i<=n;++i)if(!(a[i]&1))add(i,T,2);
	if(Dinic()!=n){puts("Impossible");return 0;}
	for(int i=1;i<=n;++i)F[i]=i,siz[i]=1;
	for(int x=1;x<=n;++x)
		if(a[x]&1){
			for(int i=head[x];i;i=nxt[i]){
				if(!c[i]){
					Merge(x,to[i]);
					G[x].push_back(to[i]);
					G[to[i]].push_back(x);
				}
			}
		}
	int tot=0;
	for(int i=1;i<=n;++i)if(Find(i)==i)tot++;
	printf("%lld\n",tot);
	for(int i=1;i<=n;++i){
		if(Find(i)==i){
			printf("%lld ",siz[i]);
			work(i,i,0);
			puts("");
		}
	}
	return 0;
}