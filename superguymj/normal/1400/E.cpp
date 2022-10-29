#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=5005;
int n,a[N];

LL solve(int l,int r,int mn)
{
	if(l>r) return 0;
	int x=0;
	rep(i,l,r) if(!x || a[x]>a[i]) x=i;
	LL rt=r-l+1;
	rt=min(rt,solve(l,x-1,a[x])+solve(x+1,r,a[x])+a[x]-mn);
	return rt;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	printf("%lld\n",solve(1,n,0));
	return 0;
}