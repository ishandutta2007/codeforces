#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=3005;
int T,n,a[N],f[N][N];
typedef long long LL;
LL ans;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n) rep(j,1,n) f[i][j]=0;
		ans=0;
		rep(i,1,n)
		{
			rep(j,i+1,n) ans+=f[a[i]][a[j]];
			rep(j,1,i-1) ++f[a[j]][a[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}