#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n,m,x1,x2;
struct xx
{
	int x,id;
	inline bool operator<(const xx &_)const{return x<_.x;}
}a[555555];
int main()
{
	scanf("%d%d%d",&n,&x1,&x2);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int tmp=(x1+a[i].x-1)/a[i].x+i;
		if(tmp>n)continue;
		long long qwq=1ll*a[tmp].x*(n-tmp+1);
		if(qwq>=x2)
		{
			printf("Yes\n");
			printf("%d %d\n",tmp-i,n-tmp+1);
			for(int j=i;j<tmp;j++)
			{
				printf("%d ",a[j].id);
			}
			printf("\n");
			for(int j=tmp;j<=n;j++)
			{
				printf("%d ",a[j].id);
			}
			printf("\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=(x2+a[i].x-1)/a[i].x+i;
		if(tmp>n)continue;
		long long qwq=1ll*a[tmp].x*(n-tmp+1);
		if(qwq>=x1)
		{
			printf("Yes\n");
			printf("%d %d\n",n-tmp+1,tmp-i);
			for(int j=tmp;j<=n;j++)
			{
				printf("%d ",a[j].id);
			}
			printf("\n");
			for(int j=i;j<tmp;j++)
			{
				printf("%d ",a[j].id);
			}
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}