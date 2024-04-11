#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=300005;
typedef long long LL;
int n,a[N],mx;
vector <int> vt[1<<20];
LL ans;

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) a[i]^=a[i-1],mx=max(mx,a[i]);
	rep(i,0,n) vt[a[i]].pb(i);
	rep(i,0,mx)
	{
		int sz=vt[i].size();
		int f0=0,f1=0;
		rep(j,0,sz-1)
		{
			if(vt[i][j]&1) ans+=f0,++f0;
			else ans+=f1,++f1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}