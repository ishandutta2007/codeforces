#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
typedef long long ll;
const int N=100005;
int n,m; ll a[N],b[N],L,R,mid;
bool check(ll t)
{
	int j=1;
	rep(i,n){
		if (b[j]-a[i]>t) continue;
		if (a[i]-b[j]>t) return 0;
		ll reach=max(b[j]+t-abs(a[i]-b[j]),(t-abs(a[i]-b[j]))/2+a[i]);
		while (j<=m && b[j]<=reach) j++;
		if (j>m) return 1;
		}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%I64d",a+i);
	rep(i,m) scanf("%I64d",b+i);
	L=0,R=20000000000LL;
	while (L<R){
		mid=(L+R)/2;
		if (check(mid)) R=mid; else L=mid+1;
		}
	printf("%I64d\n",L);
	return 0;
}