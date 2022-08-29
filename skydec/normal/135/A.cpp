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
#define MAXN 110000
int a[MAXN];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);a[0]=1;
	for(int i=1;i<n;i++)printf("%d ",a[i-1]);
	if(a[n]==1)a[n]++;else a[n]=a[n-1];printf("%d\n",a[n]);
	return 0;
}