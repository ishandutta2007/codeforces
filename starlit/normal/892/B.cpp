#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 1000006
using namespace std;
int n,l[N],ans,now;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",l+i);
	now=n+1;
	for(int i=n;i;i--)
	{
		if(now>i)ans++;
		now=min(now,i-l[i]);
	}
	printf("%d",ans);
}