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

const int N=10005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
template<class T> inline void read(T &x){
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
template<class T> inline void print(T x){
	if(!x){puts("0");return;}
	if(x<0){putchar('-');x=-x;}
	int a[20],m=0;
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');puts("");
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int to,next,w;}p[N<<1];
int tot,head[N],vis[N],a[N],l[N];
int n,m,L,S,T,u[N],v[N],w[N],to[N],from[N];
ll d[N],ds[N],dt[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void add(int x,int y,int z){
	p[++tot]=(node){y,head[x],z};head[x]=tot;
	p[++tot]=(node){x,head[y],z};head[y]=tot;
}
void dijstra(ll *d){
	clr(vis,0);
	for(int i=1;i<=n;i++) d[i]=inf;
	d[S]=0;q.push(mp(0,S));
	while(!q.empty()){
		int x=q.top().SS;q.pop();
		for(int i=head[x];i;i=p[i].next){
			int y=p[i].to;
			if(d[y]>d[x]+p[i].w){
				d[y]=d[x]+p[i].w;
				from[y]=i;to[y]=x;
				q.push(mp(d[y],y));
			}
		}
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
#endif
	ios::sync_with_stdio(0);
	read(n);read(m);read(L);read(S);read(T);
	S++;T++;tot=1;
	for(int i=1;i<=m;i++){
		read(u[i]);read(v[i]);read(w[i]);
		u[i]++;v[i]++;
		if(w[i]) add(u[i],v[i],w[i]); else add(u[i],v[i],inf);
	}
	dijstra(ds);swap(S,T);
	dijstra(dt);swap(S,T);
	if(ds[T]<L){puts("NO");return 0;}
	if(ds[T]==L){
		puts("YES");
		for(int i=1;i<=m;i++)
			printf("%d %d %d\n",u[i]-1,v[i]-1,w[i]?w[i]:inf);
		return 0;
	}
	for(int i=1;i<=tot;i++) if(p[i].w==inf) p[i].w=1;
	dijstra(d);
	if(d[T]>L){puts("NO");return 0;}
	int k=T,tot=0;
	while(k!=S) a[++tot]=k,k=to[k];
	reverse(a+1,a+tot+1);
	int now=0;
	for(int i=1;i<=tot;i++){
		int x=from[a[i]]>>1;
		if(!w[x]) w[x]=max(1ll,L-dt[a[i]]-now);
		now+=w[x];
		if(now==L-dt[a[i]]) break;
	}
	puts("YES");
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",u[i]-1,v[i]-1,w[i]?w[i]:inf);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}