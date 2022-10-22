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
int n;
int m;
int a[11][11];
int link[11];
int fa[11];
vector<PII>ans[11][11];
int pw[11];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int p[11];
void Link(int i,int j,int k){
	if(i>j) swap(i,j);
	a[i][j]-=k;
	if(k==1) ans[i][j].pb(mp(pw[i-1],pw[j-1]));
}
int s,t;
int tot=1;
int head[101],tmp[101],nxt[2010],to[2010],w[2010];
int depth[101],gap[101];
int id[11][11][2];
void add(int x,int y,int z){
	// printf("x:%d,y:%d,z:%d\n",x,y,z);
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0;
}
bool bfs(int s,int t){
	queue<int>q;
	memset(depth,0,sizeof(depth));memset(gap,0,sizeof(gap));
	while(!q.empty()) q.pop();
	q.push(t);
	depth[t]=1;
	gap[1]++;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(depth[v]==0){
				depth[v]=depth[u]+1;
				gap[depth[v]]++;
				q.push(v);
			}
		}
	}
	if(depth[s]==0) return 0;
	return 1;
}
int dfs(int x,int maxf){
	if(x==t) return maxf;
	int sum=0;
	for(int &i=tmp[x];i;i=nxt[i]){
		int v=to[i];
		if(depth[v]+1==depth[x]){
			int di=dfs(v,min(maxf,w[i]));
			w[i]-=di;
			w[i^1]+=di;
			maxf-=di;
			sum+=di;
			if(maxf==0) return sum;
		}
	}
	if(--gap[depth[x]]==0) depth[s]=t+1;
	++gap[++depth[x]];tmp[x]=head[x];
	return sum;
}
inline int ISAP(int s,int t){
	int maxflow=0;
	if(bfs(s,t)==0) return 0;
	for(int i=1;i<=t;++i) tmp[i]=head[i];
	while(depth[s]<=t) {
		maxflow+=dfs(s,2e9);
	}
	return maxflow;
}
PII e[200010];
int cnt=0;
bool vis[1<<22];
void solve(){
	memset(head,0,sizeof(head));
	s=m*m+m+1;t=s+1;tot=1;
	for(int i=1;i<=m;++i){
		for(int j=i;j<=m;++j){
			if(a[i][j]<0) return ;
			// if(a[i][j]==0) continue ;
			// printf("i:%d,j:%d,a:%d\n",i,j,a[i][j]);
			add(s,(i-1)*m+j,a[i][j]);
			id[i][j][0]=tot+2;
			add((i-1)*m+j,m*m+i,n);
			id[i][j][1]=tot+2;
			add((i-1)*m+j,m*m+j,n);
		}
	}
	// for(int i=1;i<=m;++i) printf("%d\n",pw[i]);
	for(int i=1;i<=m;++i) add(m*m+i,t,min(n+1,pw[i])-pw[i-1]-1),p[i]=0;
	int f=ISAP(s,t);
	// printf("flow:%d\n",f);
	if(f==n-m){
		for(int i=1;i<=m;++i){
			for(int j=i;j<=m;++j){
				while(w[id[i][j][0]]>0){
					++p[i];ans[i][j].pb(mp(pw[i-1]+p[i],pw[j-1]));--w[id[i][j][0]];
				}
				while(w[id[i][j][1]]>0){
					++p[j];ans[i][j].pb(mp(pw[i-1],pw[j-1]+p[j]));--w[id[i][j][1]];
				}
			}
		}
		for(int i=1;i<n;++i){
			printf("%d %d\n",ans[e[i].fi][e[i].se].back().fi,ans[e[i].fi][e[i].se].back().se);
			ans[e[i].fi][e[i].se].pop_back();
		}
		exit(0);
	}
}
void check(){
	for(int i=1;i<=m;++i) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;++i){
		if(link[i]==i) ++cnt;
		else {
			int fx=find(i),fy=find(link[i]);
			if(fx==fy) return ;
			fa[fx]=fy;
		}
	}
	if(cnt!=1) return ;
	int t=0;
	auto pid=[&](int i,int j){
		int s=0;
		for(int p=1;p<i;++p) s+=(m-p);
		s+=m-j+1;return s;
	};
	for(int i=1;i<=m;++i){
		if(i!=link[i]){
			t|=(1<<pid(min(i,link[i]),max(i,link[i])));
		}
		// printf("i:%d,lnk:%d\n",i,link[i]);
		if(i!=link[i]) Link(i,link[i],1);
	}
	if(vis[t]) return ;
	vis[t]=1;++cnt;
	solve();
	if(cnt%125==0&&n>10000){
		printf("%d\n",cnt);
		exit(0);
	}
	// printf("failed\n");
	for(int i=1;i<=m;++i){
		if(i!=link[i]) Link(i,link[i],-1);
	}
	for(int i=1;i<=m;++i) for(int j=1;j<=m;++j) ans[i][j].clear();
}
void dfs(int x){
	if(x==m+1){
		check();return ;
	}
	for(int i=1;i<=m;++i){
		link[x]=i;dfs(x+1);
	}
}
int main(){
	n=read();
	int t=n;
	while(t){
		++m;t/=10;
	}
	pw[0]=1;
	for(int i=1;i<=m;++i) pw[i]=10*pw[i-1];
	for(int i=1;i<n;++i){
		char s[11];
		scanf("%s",s+1);
		int l1=strlen(s+1);
		scanf("%s",s+1);
		int l2=strlen(s+1);
		e[i]=mp(min(l1,l2),max(l1,l2));
		a[min(l1,l2)][max(l1,l2)]++;
	}dfs(1);puts("-1");
}