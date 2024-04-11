#include<bits/stdc++.h>
using namespace std;
int t,n,k,sum,f[31],a[31],b[31];
bool cmp1(int x,int y)
{
	return x<y;
}
bool cmp2(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp2);
		for(int i=1;i<=n;i++)
			f[i]=b[i]-a[i];
		for(int i=1;i<=k&&f[i]>0;i++)
			sum+=f[i];
		cout<<sum<<endl;
	}
	return 0;
}