#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=100005;
const LL INF=1000000000000000000ll;
int n,tot,ans;
LL k,mn,mx,p[1000005],idl[N],idr[N];
struct data{LL l,r;} dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool cmp1(data a,data b){return a.l<b.l;}
bool cmp2(data a,data b){return a.r<b.r;}

void dfs(int x,LL y)
{
	if(x>19 || y>mx) return;
	if(y) p[++tot]=y;
	dfs(x+1,y*10+4);
	dfs(x+1,y*10+7);
}

const LL base=1000000000;
struct num
{
	LL a[5];

	void st(LL x=0)
	{
		rep(i,0,4) a[i]=0;
		for(int i=0; x; a[i]=x%base,x/=base,++i);
	}

	void operator += (num x)
	{
		rep(i,0,4) a[i]+=x.a[i];
		rep(i,0,3) a[i+1]+=a[i]/base,a[i]%=base;
	}
} L[N],R[N];
	
num operator - (num x,num y)
{
	rep(i,0,4) x.a[i]-=y.a[i];
	rep(i,0,3) if(x.a[i]<0) x.a[i]+=base,--x.a[i+1];
	return x;
}

num operator * (num x,LL y)
{
	rep(i,0,4) x.a[i]*=y;
	rep(i,0,3) x.a[i+1]+=x.a[i]/base,x.a[i]%=base;
	return x;
}

void pre()
{
	sort(dat+1,dat+1+n,cmp1);
	rep(i,1,n) L[i].st(dat[i].l),idl[i]=dat[i].l;
	rep(i,1,n) L[i]+=L[i-1];

	sort(dat+1,dat+1+n,cmp2);
	rep(i,1,n) R[i].st(dat[i].r),idr[i]=dat[i].r;
	rep(i,1,n) R[i]+=R[i-1];
}

bool cmp(num a,num b)
{
	repd(i,4,0)
	{
		if(a.a[i]>b.a[i]) return 1;
		if(a.a[i]<b.a[i]) return 0;
	}
	return 0;
}

bool check(int x,int y)
{
	if(p[y]-p[x]+1>mn) return 0;
	num ql,qr;
	ql.st(p[x]),qr.st(p[y]);

	num ret,K;
	ret.st(),K.st(k);

	int l=1,r=n;
	while(l<=r) idl[mid]<=p[x]?l=mid+1:r=mid-1;

	ret+=(L[n]-L[l-1])-ql*(n-l+1);

	if(cmp(ret,K)) return 0;
	
	l=1,r=n;
	while(l<=r) idr[mid]>=p[y]?r=mid-1:l=mid+1;
	
	ret+=qr*r-R[r];

	if(cmp(ret,K)) return 0;

	return 1;
}

int main()
{
	n=getint(),k=getLL();
	mn=INF,mx=0;
	rep(i,1,n) dat[i].l=getLL(),dat[i].r=getLL(),mn=min(mn,dat[i].r-dat[i].l+1),mx=max(mx,dat[i].r);
	mx+=k,dfs(1,0);
	sort(p+1,p+1+tot);
	pre();
	rep(i,1,tot)
	{
		int l=i+ans,r=tot;
		if(l>r || !check(i,l)) continue;
		while(l<=r)
			check(i,mid)?l=mid+1:r=mid-1;
		ans=max(ans,l-i);
	}
	printf("%d\n",ans);
	return 0;
}