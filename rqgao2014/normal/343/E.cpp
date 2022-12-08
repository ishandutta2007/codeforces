#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=205,M=10005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next,cap;}p[M];
struct edge{int u,v,c;}Q[N];
int n,m,tot,S,T,ans,head[N],st[N],fa[N];
bool vis[N];
vi res[N];
queue<int> q;

void add(int x,int y,int z){
	p[tot]=(node){y,head[x],z};head[x]=tot++;
	p[tot]=(node){x,head[y],z};head[y]=tot++;
}
bool bfs(){
	clr(st,0);
	q.push(S);st[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];~i;i=p[i].next){
			int y=p[i].to;
			if(st[y]||!p[i].cap) continue;
			st[y]=st[x]+1;q.push(y);
		}
	}
	return st[T];
}
int dfs(int x,int f){
	if(x==T) return f;
	int r=0;
	for(int i=head[x];~i;i=p[i].next){
		int y=p[i].to,tmp;
		if(st[y]!=st[x]+1||!p[i].cap) continue;
		tmp=dfs(y,min(f-r,p[i].cap));
		p[i].cap-=tmp;p[i^1].cap+=tmp;
		r+=tmp;
		if(r==f) return f;
	}
	if(!r) st[x]=-2;
	return r;
}
int dinic(){
	int ans=0,t;
	while(bfs()){
		while(t=dfs(S,inf)) ans+=t;
	}
	return ans;
}
void dfs(int x){
	vis[x]=1;
	for(int i=head[x];~i;i=p[i].next){
		int y=p[i].to;
		if(!p[i].cap||vis[y]) continue;
		dfs(y);
	}
}
void solve(vi a){
	int si=a.size();
	if(si==1)return ;
	S=a[0],T=a[1];
	for(int i=0;i<m*2;i+=2) p[i].cap=p[i^1].cap=(p[i].cap+p[i^1].cap)/2;
	Q[++tot]=(edge){S,T,dinic()};
	ans+=Q[tot].c;
	clr(vis,0);dfs(S);
	vi L,R;L.clear();R.clear();
	for(int i=0;i<si;i++)
		if(vis[a[i]]) L.pb(a[i]); else R.pb(a[i]);
	solve(L);solve(R);
}
inline bool cmp(edge a,edge b){return a.c>b.c;}
inline int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	clr(head,-1);tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	vi a;a.clear();
	for(int i=1;i<=n;i++) a.pb(i);
	tot=0;solve(a);
	printf("%d\n",ans);
	sort(Q+1,Q+n,cmp);
	for(int i=1;i<=n;i++) fa[i]=i,res[i].pb(i);
	for(int i=1;i<n;i++){
		int x=find(Q[i].u),y=find(Q[i].v);
		fa[x]=y;
		for(int j=0;j<res[x].size();j++)
			res[y].pb(res[x][j]);
	}
	for(int i=0;i<n;i++) printf("%d ",res[find(1)][i]);puts("");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}