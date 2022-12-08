#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=20005,inf=1e9+7,mod=20000;

int n,m,up[N],cup[N],cnt,si[N],num[N],dep[N],use[N];
vi g[N],f[N],s[N];
bool vis[N];

// cost flow
struct node{
	int to,next,flow,cost;
}p[N<<4];
int head[N],d[N],tot,S,T,path,ans;
queue<int> q;
void add(int x,int y,int f,int w){
	if(!f) return;
//	printf("%d %d %d %d\n",x,y,f,w);
	p[tot]=(node){y,head[x],f,w};head[x]=tot++;
	p[tot]=(node){x,head[y],0,-w};head[y]=tot++;
}
int inc(int &x){x++;if(x>=mod) x-=mod;return x;}
inline int dfs(int x,int f){
	if(x==T){ans-=d[x]*f;return f;}
//	debug(x);
	vis[x]=1;
	int r=f;
	for(int i=head[x];~i;i=p[i].next){
		int y=p[i].to,tmp;
		if(!p[i].flow||d[y]!=d[x]+p[i].cost||vis[y]) continue;
		tmp=dfs(y,min(r,p[i].flow));
		p[i].flow-=tmp;p[i^1].flow+=tmp;
		r-=tmp;
		if(!r) return f;
	}
	return f-r;
}
bool spfa(){
	for(int i=S;i<=T;i++) d[i]=inf,vis[i]=0;
	vis[S]=1;q.push(S);d[S]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];~i;i=p[i].next){
			if(!p[i].flow) continue;
			int y=p[i].to,w=p[i].cost;
			if(d[y]>d[x]+w){
				d[y]=d[x]+w;
				if(!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
//	debug(d[T]);
	return d[T]<inf;
}


//build
inline void Add(int x,int y,int z){
	g[x].pb(y);f[x].pb(z);
	g[y].pb(x);f[y].pb(z);
	vis[x]=vis[y]=1;
}
inline void Dfs(int x,int fa){
	vis[x]=1;
//	printf("%d\n",x);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i],z=f[x][i];
		if(y==fa) continue;
		if(vis[y]&&dep[y]<dep[x]){
			cnt++;
			s[cnt].pb(z);si[z]--;
			int k=x,o=0;
//			printf("Case:%d",x);
			while(k!=y){
//				o++;
//				if(o>10000) break;
				si[cup[k]]--;
				s[cnt].pb(cup[k]);
				k=up[k];
			}
			continue;
		}
		if(vis[y]) continue;
		cup[y]=z;up[y]=x;
		dep[y]=dep[x]+1;
		Dfs(y,x);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);si[z]++;use[z]++;
	}
//	return 0;
	for(int i=1;i<=n;i++)
		if(vis[i]){
			memset(vis,0,sizeof(vis));
			Dfs(i,-1);break;
		}
//	cerr<<cnt<<endl;
//	return 0;
	clr(head,-1);
	S=0;T=cnt+1;
	for(int i=1;i<=m;i++)
		if(!si[i]&&use[i]) T++;
	int CNT=cnt;
	for(int i=1;i<=m;i++)
		if(!si[i]&&use[i]) add(num[i]=++CNT,T,use[i]-1,0),add(num[i],T,1,1);
	for(int i=1;i<=cnt;i++){
		bool isok=1;
		for(int j=0;j<s[i].size();j++)
			if(si[s[i][j]]) isok=0;
		if(isok){
			add(S,i,1,0);
			for(int j=0;j<s[i].size();j++)
				add(i,num[s[i][j]],1,0);
		}
	}
	ans=0;
	for(int i=1;i<=m;i++) if(use[i]) ans++;
	memset(use,0,sizeof(use));
	while(spfa())
		while(dfs(S,inf))clr(vis,0);
	printf("%d\n",ans);
	return 0;
}