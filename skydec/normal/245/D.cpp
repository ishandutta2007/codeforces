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
int a[105][105];int n;int ans[105];
int main()
{
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)
	{
		scanf("%d",&a[i][j]);
		if(a[i][j]!=-1)
		{
			ans[i]|=a[i][j];
			ans[j]|=a[i][j];
		}
	}
	bool f=1;
	rep(i,1,n)rep(j,1,n)if(i!=j)if((ans[i]&ans[j])!=a[i][j])f=0;
	if(!f)printf("-1\n");
	else rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}