#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const LL INF=1000000000;
int T;
LL a,b,p,q;

LL f(LL n,LL a,LL b,LL c)
{
	if(!c || n<0) return 0;
	LL A=a/c,B=b/c;
	a%=c,b%=c;
	LL ret=A*n*(n+1)/2+B*(n+1);
	LL m=(a*n+b)/c;
	return ret+m*n-f(m-1,c,c-b-1,a);
}

bool check(int l,int r)
{
	LL ret1=f(b-a,p,a*p+q-l,q);
	LL ret2=f(b-a,p,a*p+q-r-1,q);
	return ret1-ret2>0;
}

void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(!b)
	{
		d=a,x=1,y=0;
		return;
	}
	exgcd(b,a%b,d,y,x),y-=a/b*x;
}

LL find(LL x)
{
	LL d,A,B;
	exgcd(p,q,d,A,B);
	if(x%d) return INF;
	A=(A*(x/d)%(q/d)+(q/d))%(q/d);
	if(A<a) A+=((a-A-1)/(q/d)+1)*(q/d);
	return A<=b?A:INF;
}

void solve()
{
	scanf("%lld%lld%lld%lld",&a,&b,&p,&q);
	if(a==b || p==q) {printf("%lld\n",a); return;}
	p<<=1,q<<=1,p%=q;
	LL l=0,r=q/2-1;
	while(l<=r)
	{
		if(check(q/2-mid,q/2+mid)) r=mid-1;
		else l=mid+1;
	}
	++r;
	printf("%lld\n",min(find(q/2-r),find(q/2+r)));
}

int main()
{
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}