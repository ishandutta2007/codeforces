#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=300005;
int n,k,a[N];
long long s[N],ans;

int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	repd(i,n,1) s[i]=s[i+1]+a[i];
	rep(i,1,n) ans+=a[i];
	sort(s+2,s+1+n),--k;
	rep(i,n-k+1,n) ans+=s[i];
	printf("%lld\n",ans);
	return 0;
}