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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=200005,M=100005,mod=1e9+7;
const ll inf=1ll<<60;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,m,k,a[N],c[N],pos[N],rk[N],si[4];
ll res,ans=1ll<<60;
vi g[4];
struct BIT{
	ll c[N*2];
	void add(int x,int y){
		while(x<=n) c[x]+=y,x+=x&-x;
	}
	ll get(int x){
		ll ans=0;
		while(x) ans+=c[x],x-=x&-x;
		return ans;
	}
}p1,p2;
inline bool cmp(int x,int y){return c[x]<c[y];}

void make(int x){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int p;scanf("%d",&p);
		a[pos[p]]|=x;
	}
}
void del(int x){
	p1.add(x,-c[x]);
	p2.add(x,-1);res+=c[x];
}
void ins(int x){
	p1.add(x,c[x]);
	p2.add(x,1);res-=c[x];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
		pos[rk[i]]=i;
	make(1);make(2);
	for(int i=1;i<=n;i++)
		if(a[i]) g[a[i]].pb(i),si[a[i]]++;
	for(int i=1;i<=n;i++) ins(i);res=0;
	for(int i=min(si[3],k),isok=0,_end=max(0,k-min(si[1],si[2]));i>=_end;i--){
		if(k*2-i>m) break;
		if(!isok){
			for(int j=0;j<i;j++) del(g[3][j]);
			for(int j=0;j<k-i;j++) del(g[2][j]),del(g[1][j]);
			isok=1;
		}
		else ins(g[3][i]),del(g[2][k-i-1]),del(g[1][k-i-1]);
		int now=0,p=0;
		for(int j=17;~j;j--)
			if(p+(1<<j)<=n&&p2.c[p+(1<<j)]+now<=m-k*2+i) p+=(1<<j),now+=p2.c[p];
		gmin(ans,p1.get(p)+res);
	}
	printf("%lld\n",ans<inf?ans:-1);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}