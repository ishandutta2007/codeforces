#include <cstdio>
using namespace std;
int n,i,j;
long long v[2][300005];
long long s[300005];
long long ans;
long long cur;
int main()
{
	scanf("%d",&n);
	for (i=0;i<=1;i++)
		for (j=1;j<=n;j++)
			scanf("%I64d",&v[i][j]);
	for (i=1;i<=n;i++)
		s[i]=s[i-1]+v[0][i]+v[1][i];
	for (i=1;i<=n;i++)
		cur+=(long long)(i-1)*v[0][i];
	for (i=n;i;i--)
		cur+=(long long)(2*n-i)*v[1][i];
	ans=cur;
	for (i=2;i<=n;i+=2)
	{
		cur-=v[1][i-1]*(long long)(2*n-1);
		cur-=v[1][i]*(long long)(2*n-2);
		cur+=v[1][i-1]*(long long)(i*2-3);
		cur+=v[1][i]*(long long)(i*2-2);
		cur+=v[0][i]*2ll;
		cur+=(s[n]-s[i])*2ll;
		if (cur>ans)
			ans=cur;
	}
	cur=0;
	for (i=1;i<=n;i++)
		cur+=(long long)i*v[1][i];
	for (i=n;i>=2;i--)
		cur+=(long long)(2*n+1-i)*v[0][i];
	if (cur>ans)
		ans=cur;
	for (i=3;i<=n;i+=2)
	{
		cur-=v[0][i-1]*(long long)(2*n-1);
		cur-=v[0][i]*(long long)(2*n-2);
		cur+=v[0][i-1]*(long long)(i*2-3);
		cur+=v[0][i]*(long long)(i*2-2);
		cur+=v[1][i]*2ll;
		cur+=(s[n]-s[i])*2ll;
		if (cur>ans)
			ans=cur;
	}
	printf("%I64d\n",ans);
	return 0;
}