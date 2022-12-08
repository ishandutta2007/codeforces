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

const int N=1005,M=100005,mod=1e9+7;
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

struct node{int to,next,w;}p[N*N];
int n,m,tot,l,r,head[N];
bool vis[N];
pii c[N];
inline void add(int x,int y,int w){
	p[++tot]=(node){y,head[x],w};head[x]=tot;
	p[++tot]=(node){x,head[y],w};head[y]=tot;
}
void dfs(int x,int a,int b){
	if(vis[x]){
		if(c[x]!=mp(a,b)){puts("-1");exit(0);}
		return;
	}
	vis[x]=1;c[x]=mp(a,b);
	if(a<0) gmin(r,b);
	if(a>0) gmax(l,-b);
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to,w=p[i].w;
		dfs(y,-a,w-b);
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	l=0;r=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			add(i,j+n,x);
		}
	dfs(1,1,0);
	if(l>r){puts("-1");return 0;}
	int ans=0,res=0,st;
	for(int i=1;i<=n+m;i++)
		res+=c[i].FF;
	if(res<0) st=r; else st=l;
	for(int i=1;i<=n+m;i++)
		ans+=c[i].SS+st*c[i].FF;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=c[i].SS+st;j++)
			printf("row %d\n",i);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=c[i+n].SS-st;j++)
			printf("col %d\n",i);
	return 0;
}