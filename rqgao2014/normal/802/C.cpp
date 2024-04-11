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
#define inf 10000007
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=1005,M=20005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

struct node{int to,next,flow,cost;}p[M];
int n,k,S,T,tot,head[N],d[N],ans,last[N];
bool vis[N];
queue<int> q;
void add(int x,int y,int f,int c){
//	printf("%d %d %d %d\n",x,y,f,c);
	p[++tot]=(node){y,head[x],f,c};head[x]=tot;
	p[++tot]=(node){x,head[y],0,-c};head[y]=tot;
}
bool spfa(){
	clr(vis,0);
	for(int i=1;i<=n+1;i++) d[i]=inf;
	q.push(S);vis[S]=1;d[S]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(!p[i].flow) continue;
			if(d[y]>d[x]+p[i].cost){
				d[y]=d[x]+p[i].cost;
				if(!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
	return d[T]<0;
}
int dfs(int x,int f){
	if(x==T) return f;
	vis[x]=1;int r=f;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,tmp;
		if(vis[y]||!p[i].flow||d[y]!=d[x]+p[i].cost) continue;
		tmp=dfs(y,min(r,p[i].flow));
		p[i^1].flow+=tmp;p[i].flow-=tmp;
		r-=tmp;if(!r) break;
	}
	return f-r;
}
int a[N],c[N];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	tot=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=0;i<=n;i++) last[i]=n+1;
//	for(int i=1;i<=n;i++) printf("%d %d\n",i,last[i]);
	int t=n;n=0;
	for(int i=1;i<=t;i++)
		if(a[i]!=a[i-1]) a[++n]=a[i];
	S=0;T=n+1;
	reverse(a+1,a+n+1);
//	for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	for(int i=n;i;i--){
//		if(last[a[i]]==0) printf("%d %d\n",a[i],i);
		if(last[a[i]]<=n) add(i+1,last[a[i]],1,-c[a[i]]);//printf("%d %d\n",i,last[a[i]]);
		last[a[i]]=i;ans+=c[a[i]];
	}
//	debug(ans);
	for(int i=1;i<=n;i++)
		add(i,i+1,1000,0);
	add(S,1,k-1,0);
	while(spfa()){
//		debug(d[T]);
		if(d[T]>=0) break;
//		printf("%d\n",d[T]);
		int t=0;while(t=dfs(S,inf)) ans+=d[T]*t,clr(vis,0);
	}
	printf("%d\n",ans);
	return 0;
}