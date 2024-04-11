#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1005;
typedef long long LL;
int n;
LL cntx,cnty;
struct data{int x,y;} a[N],b[N];

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	rep(i,1,n) scanf("%d%d",&b[i].x,&b[i].y);
	rep(i,1,n) cntx+=a[i].x+b[i].x,cnty+=a[i].y+b[i].y;
	cntx/=n,cnty/=n;
	printf("%lld %lld\n",cntx,cnty);
	return 0;
}