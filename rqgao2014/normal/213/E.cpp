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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=200005,M=100005,m1=1e9+7,m2=998244353,base=1e5+3;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,m,a[N],b[N],ans,pos[N],pw1[N],pw2[N];
struct node{int cnt,h1,h2;}p[N<<4];
inline node operator + (const node &a,const node &b){
	return node{a.cnt+b.cnt,((ll)a.h1*pw1[b.cnt]+b.h1)%m1,((ll)a.h2*pw2[b.cnt]+b.h2)%m2};
}
void add(int l,int r,int k,int x,node b){
	if(l==r){p[k]=b;return;}
	int mid=l+r>>1;
	if(x<=mid) add(l,mid,ls,x,b); else add(mid+1,r,rs,x,b);
	p[k]=p[ls]+p[rs];
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d",&n,&m);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=m;i++) pw1[i]=(ll)pw1[i-1]*base%m1,pw2[i]=(ll)pw2[i-1]*base%m2;
	int s1=0,s2=0;
	for(int i=0;i<n;i++) s1=(s1+pw1[i])%m1,s2=(s2+pw2[i])%m2;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int h1=0,h2=0;
	for(int i=1;i<=n;i++) h1=((ll)h1*base+a[i])%m1,h2=((ll)h2*base+a[i])%m2;
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),pos[b[i]]=i;
	for(int i=1;i<n;i++) add(1,m,1,pos[i],node{1,i,i});
	for(int i=n;i<=m;i++){
		add(1,m,1,pos[i],node{1,i,i});
		if(i>n) add(1,m,1,pos[i-n],node{0,0,0});
		int t1=((ll)s1*(i-n)+h1)%m1,t2=((ll)s2*(i-n)+h2)%m2;
//		printf("%d %d\n",p[1].h1,p[1].h2);
		if(p[1].h1==t1&&p[1].h2==t2) ans++;
	}
	printf("%d\n",ans);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}