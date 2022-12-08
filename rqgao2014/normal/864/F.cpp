#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP priority_queue
#define heap(T) priority_queue<T,vector<T>,greater<T> >
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

const int N=3005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
const int BufferSize=1<<25;
char buffer[BufferSize],*Bufferhead,*Buffertail;
int Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T> inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	x=rev?-x:x;
	return 1;
}
template<class T>inline void print(T x,const char c){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int x,y,k,num;}query[400005];
int n,m,Q,a[N],ans[400005];
vi g[N];
vector<pii> ask[N];
bool vis[N],v[N],bad[N];
void make(int x){
	if(bad[x]) return;
	bad[x]=1;
	for(int y:g[x]) make(y);
}
void dfs(int x,int d=1){
	if(bad[x]) return;
	if(v[x]){make(x);return;}
	if(vis[x]) return;
	vis[x]=v[x]=1;a[d]=x;
	for(auto i:ask[x])
		if(d>=i.FF) ans[i.SS]=a[i.FF];
	for(int y:g[x]) dfs(y,d+1);
	v[x]=0;
}

inline bool cmp(node a,node b){return a.x<b.x;}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);	
	}
	for(int i=1;i<=Q;i++){
		int x,y,k;scanf("%d%d%d",&x,&y,&k);
		query[i]=(node){x,y,k,i};
	}
	clr(ans,-1);
	sort(query+1,query+Q+1,cmp);
	for(int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end());
	for(int i=1,j=1;i<=n;i++){
//		debug(i);
		clr(vis,0);clr(v,0);clr(bad,0);
		for(int k=1;k<=n;k++) ask[k].clear();
		while(j<=Q&&query[j].x==i){
			ask[query[j].y].pb(mp(query[j].k,query[j].num));
			j++;
		}
		dfs(i);
	}
	for(int i=1;i<=Q;i++) print(ans[i],'\n');
	return 0;
}