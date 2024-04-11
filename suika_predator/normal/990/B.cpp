#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,ans;
int a[233333];
int main()
{
	scanf("%d%d",&n,&m);ans=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int last=1;
	for(int i=2;i<=n;i++)
	{
		while(a[i]>a[last])
		{
			if(a[i]<=a[last]+m)last++,ans--;
			else last++;
		}
		
	}
	printf("%d\n",ans);
	return 0;
}