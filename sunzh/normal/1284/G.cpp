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
int T;
int n,m;
char str[21][21];
int tot;
int head[610],nxt[200010],to[200010],w[200010];
int depth[610],gap[610];
int stk[610],top;
vector<int>vec[610],st[610];
int dfn[610],low[610],idx;
bool vis[610];
int fa[610];
int ccnt;
int belong[610];
int siz[610];
void tarjan(int x){
	dfn[x]=++idx,low[x]=idx;stk[++top]=x;vis[x]=1;
	for(int v:vec[x]){
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[x]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		++ccnt;siz[ccnt]=0;vector<int>().swap(st[ccnt]);
		while(stk[top]!=x){
			vis[stk[top]]=0;
			st[ccnt].pb(stk[top]);
			belong[stk[top]]=ccnt;--top;++siz[ccnt];
		}siz[ccnt]++;st[ccnt].pb(x);
		--top;belong[x]=ccnt;vis[x]=0;
	}
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int s,t;
bool gt[610];
void add(int x,int y,int z){
	// printf("x:%d,y:%d,z:%d\n",x,y,z);
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z;
	nxt[++tot]=head[y],head[y]=tot,to[tot]=x,w[tot]=0;
}
int getid(int x,int y){
	if(x==1&&y==0) return n*m+1;
	if(x==0&&y==1) return n*m+2;
	if(x<1||x>n||y<1||y>m) return 0;
	return (x-1)*m+y;
}
PII getpos(int x){
	if(x>n*m) return (x==n*m+1?(mp(1,0)):(mp(0,1)));
	else return mp((x-1)/m+1,(x-1)%m+1);
}
int id[21][21][4];
int tmp[610];
bool Bfs(int s,int t){
	memset(depth,0,sizeof(depth));
	memset(gap,0,sizeof(gap));
	queue<int>q;
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
	if(--gap[depth[x]]==0) depth[s]=t+2;
	++gap[++depth[x]];tmp[x]=head[x];
	return sum;
}
inline int ISAP(int s,int t){
	int maxflow=0;
	if(Bfs(s,t)==0) return 0;
	for(int i=0;i<=t;++i) tmp[i]=head[i];
	while(depth[s]<=t+1) {
		maxflow+=dfs(s,0x3f3f3f3f);
	}
	return maxflow;
}
char ans[51][51];
void resetans(){
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			ans[i<<1|1][j<<1|1]=str[i][j];
		}
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void mer(int x,int y){
	// printf("x:%d,y:%d\n",x,y);
	fa[find(x)]=find(y);
	PII poa=getpos(x),pob=getpos(y);
	// printf("%d %d,%d %d\n",poa.fi,poa.se,pob.fi,pob.se);
	ans[(poa.fi<<1|1)+(pob.fi<<1|1)>>1][(poa.se<<1|1)+(pob.se<<1|1)>>1]='O';
}
vector<int>rev[610];
void bfs(int x){
	queue<int>Q;
	Q.push(x);memset(vis,0,sizeof(vis));vis[x]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:rev[u]){
			if(find(u)!=find(v)) mer(u,v);
			if(!vis[v]) Q.push(v),vis[v]=1;
		}
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		memset(head,0,sizeof(head));tot=1;
		for(int i=1;i<=n*m+5;++i)vector<int>().swap(vec[i]),vector<int>().swap(rev[i]);
		for(int i=1;i<=n;++i) scanf("%s",str[i]+1);
		str[0][1]=str[1][0]='O';
		memset(id,0,sizeof(id));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j) if(str[i][j]=='O'&& !((i+j)&1)){
				for(int k=0;k<4;++k){
					int vx=i+dx[k],vy=j+dy[k];
					if(vx<0||vx>n||vy<0||vy>m) continue ;
					if(str[vx][vy]=='O') id[i][j][k]=tot+1,add(getid(i,j),getid(vx,vy),1);
				}
			}
		}
		int cnt=0;
		s=0,t=n*m+5;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j) if(str[i][j]=='O'){
				if((i+j)&1) add(getid(i,j),t,1);
				else add(s,getid(i,j),1),++cnt;
			}
		}
		int f=ISAP(s,t);
		// printf("f:%d\n",f);
		if(f!=cnt){
			puts("NO");continue ;
		}
		for(int i=0;i<=n*m+2;++i) fa[i]=i;
		resetans();
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j) if(str[i][j]=='O'&&!((i+j)&1)){
				for(int k=0;k<4;++k){
					if(id[i][j][k]){
						int vx=i+dx[k],vy=j+dy[k];
						if(!w[id[i][j][k]]) vec[getid(vx,vy)].pb(getid(i,j)),rev[getid(i,j)].pb(getid(vx,vy)),mer(getid(vx,vy),getid(i,j));
						vec[getid(i,j)].pb(getid(vx,vy));
						rev[getid(vx,vy)].pb(getid(i,j));
					}
				}
			}
		}
		bool fl=0;
		memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));top=0;
		memset(vis,0,sizeof(vis));ccnt=0;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j) if(str[i][j]=='O'){
				if(!dfn[getid(i,j)]){
					// printf("tarjan:%d\n",getid(i,j));
					tarjan(getid(i,j));
				}
			}
		}
		for(int i=1;i<=ccnt;++i){
			gt[i]=(siz[i]==1);
			for(int j:st[i]){
				for(int v:vec[j]) gt[i]|=gt[belong[v]];
			}
			if(!gt[i]) fl=1;
		}
		if(fl){
			puts("NO");continue ;
		}
		printf("YES\n");
		for(int i=1;i<=ccnt;++i){
			if(siz[i]==1){
				// printf("bfs:%d\n",st[i][0]);
				bfs(st[i][0]);
			}
		}
		for(int i=3;i<=(n<<1|1);++i){
			for(int j=3;j<=(m<<1|1);++j){
				if(ans[i][j]) printf("%c",ans[i][j]);else printf(" ");
			}
			printf("\n");
		}
	}
}