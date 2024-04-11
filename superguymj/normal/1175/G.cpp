#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=20005,K=105;
typedef long long LL;
const LL INF=100000000000000ll;
struct P {LL x,y;} ;
bool jdg;
int n,k,a[N],L[N],R[N];
LL f[N],g[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int top;
P stk[N];	

double calc(P x,P y)
{
	return (double)(x.x-y.x)/(x.y-y.y);
}

bool cmp(double x,double y)
{
	return jdg?x<=y:x>=y;
}

void ins(LL x,LL y)
{
	while(top && stk[top].y==y) x=min(x,stk[top].x),--top;
	while(top>1 && cmp(calc(stk[top],(P){x,y}),calc(stk[top-1],stk[top]))) --top;
	stk[++top]=(P){x,y};
}

LL query(LL x)
{
	if(!top) return INF;
	while(top>1 && stk[top].x+stk[top].y*x>=stk[top-1].x+stk[top-1].y*x) --top;
	return stk[top].x+stk[top].y*x;
}

void solve(int l,int r)
{
	if(l==r)
	{
		f[l]=min(f[l],g[l-1]+a[l]);
		return;
	}

	solve(l,mid);
	solve(mid+1,r);

	L[mid+1]=0;
	repd(i,mid,l) L[i]=max(L[i+1],a[i]);
	R[mid]=0;
	rep(i,mid+1,r) R[i]=max(R[i-1],a[i]);
	int p;

	top=0,p=mid+1,jdg=1;
	rep(i,mid+1,r)
	{
		while(p-1>=l && L[p-1]<=R[i])
			--p,ins(g[p-1],-p+1);
		f[i]=min(f[i],query(R[i])+(LL)i*R[i]);
	}

	top=0,p=l-1,jdg=0;
	repd(i,r,mid+1)
	{
		while(p+1<=mid && L[p+1]>=R[i]) ++p,ins(g[p-1]-(LL)(p-1)*L[p],L[p]);
		f[i]=min(f[i],query(i));
	}
}	

int main()
{
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) g[i]=INF;
	rep(i,1,k)
	{
		rep(j,0,n) f[j]=INF;
		solve(1,n);
		rep(j,0,n) swap(f[j],g[j]);
	}
	printf("%lld\n",g[n]);
	return 0;
}