#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
 
using namespace std;
const int N=1000005;
typedef long long LL;
LL ans;
int n,m,k,a[N],b[N],A[N],B[N],sa[N],sb[N];
map <int,int> mpx[N],mpy[N];
 
int find(int a[],int n,int x)
{
	int l=1,r=n;
	while(l<=r) a[mid]>=x?r=mid-1:l=mid+1;
	return r+1;
}
 
void solve()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) scanf("%d",&a[i]),A[a[i]]=i;
	rep(i,1,m) scanf("%d",&b[i]),B[b[i]]=i;
	rep(i,1,n) mpx[i].clear(),sb[i]=0;
	rep(i,1,m) mpy[i].clear(),sa[i]=0;
	ans=0;
	rep(i,1,k)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(A[x] && B[y]) continue;
		if(A[x])
		{
			int t=find(b,m,y);
			ans+=sa[t]-mpx[A[x]][t];
			++mpx[A[x]][t],++sa[t];
		}
		if(B[y])
		{
			int t=find(a,n,x);
			ans+=sb[t]-mpy[B[y]][t];
			++mpy[B[y]][t],++sb[t];
		}
	}
	printf("%lld\n",ans);
	rep(i,1,n) A[a[i]]=0;
	rep(i,1,m) B[b[i]]=0;
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}