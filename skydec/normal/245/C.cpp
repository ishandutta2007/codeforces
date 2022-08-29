#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 105
int n;int ans=0;int a[MAXN];
int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		bool f=0;
		if(2*i+1<=n)f=1;
		if((i&1)&&(i!=1)&&(i/2>0))f=1;
		if((i%2==0)&&(i/2>0)&&(i+1<=n))f=1;
		if(f)
		{
			ans+=a[i];
			a[i^1]=max(a[i^1]-a[i],0);
			a[i/2]=max(a[i/2]-a[i],0);
			a[i]=0;
		}
		else if(a[i]){printf("-1\n");return 0;}
	}
	printf("%d\n",ans);
}