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
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const ll inf=1ll<<60,INF=1ll<<40;
const int N=2005,M=120005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct answer_node{int cnt,edg[10];}res1,res2;
struct node{int to,next;ll cap;}p[M];
int n,m,tot=1,S,T,head[N],st[N];
bool vis[N];
queue<int> q;

inline void add(int x,int y,ll z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],z};head[y]=tot;
}
bool bfs(){
	clr(st,-1);
	q.push(S);st[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(~st[y]||!p[i].cap) continue;
			st[y]=st[x]+1;q.push(y);
		}
	}
	return st[T]>0;
}
ll dfs(int x,ll f){
	if(x==T) return f;
	ll r=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(st[y]!=st[x]+1||!p[i].cap) continue;
		ll tmp=dfs(y,min(p[i].cap,f-r));
		if(!tmp) continue;
		p[i].cap-=tmp,p[i^1].cap+=tmp;
		return tmp;
	}
	if(!r) st[x]=-1;
	return 0;
}
ll dinic(){
	ll ans=0,t;
	while(bfs()){
		while(t=dfs(S,inf)){
			ans+=t;
			if(ans>=INF*3) return ans;
		}
	}return ans;
}
inline void srch(int x){
	vis[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]||!p[i].cap) continue;
		srch(y);
	}
}
void getans(answer_node &a){
	clr(vis,0);
	srch(S);
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(int j=head[i];j;j=p[j].next){
			int x=p[j].to;
			if(!vis[x]&&!p[j].cap) a.edg[++a.cnt]=j>>1;
		}
	}
}
void print(answer_node a){
	printf("%d\n",a.cnt);
	for(int i=1;i<=a.cnt;i++) 
		printf("%d ",a.edg[i]);
	puts("");
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		add(x,y,INF+z);
	}
	ll t1=dinic(),t2,ans;
	if(!t1){puts("0\n0");return 0;}
	if(t1>=INF*3){puts("-1");return 0;}
	getans(res1);
	if(t1>=INF*2){
		printf("%lld\n",t1-INF*2);
		print(res1);
		return 0;
	}
	ans=t1-INF;
	for(int i=2;i<=m*2+1;i+=2){
		p[i].cap=p[i^1].cap=(p[i].cap+p[i^1].cap)>>1;
		if(p[i].cap>=INF+ans) p[i].cap=p[i^1].cap=inf;
	}
	t2=dinic();
	if(t2-INF*2<ans){
//		debuge;
		getans(res2);
		printf("%lld\n",t2-INF*2);
		print(res2);
	}else{
		printf("%lld\n",ans);
		print(res1);
	}
	return 0;
}