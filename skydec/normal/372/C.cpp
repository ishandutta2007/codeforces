#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long LL;
#define MAXN 305
int n,m,d;
int a[MAXN],b[MAXN],t[MAXN];
LL f[2][160000];
int dl[160000];int l,r;
int main()
{
	scanf("%d%d%d",&n,&m,&d);int now=0;
	rep(i,1,m)scanf("%d%d%d",&a[i],&b[i],&t[i]);
	rep(i,1,m)
	{
		now^=1;
		LL step=d*1ll*(t[i]-t[i-1]);
		l=1;r=0;
		rep(j,1,n)
		{
			while((l<=r)&&(f[now^1][j]>f[now^1][dl[r]]))r--;
			dl[++r]=j;
			while((l<=r)&&(dl[l]+step<j))l++;
			//printf("%d %d %d\n",i,j,dl[l]);
			f[now][j]=f[now^1][dl[l]]+1ll*(b[i]-abs(a[i]-j));
		}
		l=1;r=0;
		per(j,n,1)
		{
			while((l<=r)&&(f[now^1][j]>f[now^1][dl[r]]))r--;
			dl[++r]=j;
			while((l<=r)&&(j+step<dl[l]))l++;
			//printf("%d %d %d\n",i,j,dl[l]);
			LL res=f[now^1][dl[l]]+1ll*(b[i]-abs(a[i]-j));
			if(res>f[now][j])f[now][j]=res;
		}
	}
	LL res=-(LL)1e16;
	rep(i,1,n)
	{
		//printf("%d %I64d\n",i,f[now^1][i]);
		res=max(res,f[now][i]);
	}
	printf("%I64d\n",res);
	return 0;
}