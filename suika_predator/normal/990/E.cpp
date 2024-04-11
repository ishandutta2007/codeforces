#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,k;
int s[1111111],a[1111111];
int l[2333333];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n*2;i++)l[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&s[i]);
		if(s[i]==0)return printf("-1\n"),0;
		l[s[i]]=l[s[i]-1];
	}
	long long minn=0x3f3f3f3f3f3f3f3fll,sum;
	int p;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		sum=0;
		for(p=0;p<n&&p!=l[p+i];p=l[p+i],sum+=a[i]);
		if(p>=n)minn=min(minn,sum);
	}
	if(minn==0x3f3f3f3f3f3f3f3fll)printf("-1\n");
	else printf("%lld\n",minn);
	return 0;
}