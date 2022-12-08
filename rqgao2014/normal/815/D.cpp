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

const int N=500005,M=1<<21,mod=1e9+7;
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

int n,a,b,c,mn[M],mx[M],flag[M];
ll p[M];
vector<pii> g[N];

void add(int l,int r,int k,int b){
	p[k]=(ll)(r-l+1)*b;
	mx[k]=mn[k]=b;flag[k]=b;
}
void push(int l,int r,int k){
	if(!flag[k]) return;
	int mid=l+r>>1;
	add(l,mid,ls,flag[k]);
	add(mid+1,r,rs,flag[k]);
	flag[k]=0;
}
void upt(int k){
	mn[k]=mn[rs];mx[k]=mx[ls];
	p[k]=p[ls]+p[rs];
}
void change(int l,int r,int x,int y,int k,int b){
	if(mx[k]<=b) return;
	if(x<=l&&r<=y){
		if(mn[k]>b){add(l,r,k,b);return;}
		push(l,r,k);
		int mid=l+r>>1;
		change(l,mid,x,y,ls,b);
		change(mid+1,r,x,y,rs,b);
		upt(k);
		return;
	}
	push(l,r,k);
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,y,ls,b);
	if(y>mid) change(mid+1,r,x,y,rs,b);
	upt(k);
}
void build(int l,int r,int k){
	if(l==r){p[k]=mn[k]=mx[k]=c+1;return;}
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	upt(k);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=1;i<=n;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		x=a-x;y=b-y;z=c-z;
		g[1].pb(mp(y+1,z+1));
		g[x+1].pb(mp(1,z+1));
		g[x+1].pb(mp(y+1,1));
	}
	build(1,b,1);
	ll ans=0;
	for(int i=1;i<=a;i++){
		for(int j=0;j<g[i].size();j++){
			int x=g[i][j].FF,y=g[i][j].SS;
			if(x>b) continue;
			change(1,b,x,b,1,y);
		}
//		printf("%d\n",p[1]);
		ans+=p[1]-b;
	}
//	debug(ans);
	printf("%lld\n",ans);
	return 0;
}