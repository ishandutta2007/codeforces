#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=1000005;
int n;
LL b[N],a[N];

int main()
{
	scanf("%d",&n);
	LL s=0;
	rep(i,1,n) scanf("%lld",&a[i]),s+=a[i];
	s-=(LL)(n-1)*(n-2)/2;
	LL p=s%n,x=(s-p)/n;
	b[1]=x;
	rep(i,2,p+1) b[i]=b[i-1]+1;
	b[p+2]=b[p+1];
	rep(i,p+3,n) b[i]=b[i-1]+1;
	rep(i,1,n) printf("%lld ",b[i]);
	return 0;
}