#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
const int MAXN=2100010;
int n,m;
int a[2010],b[2010],t[MAXN];
int main()
{
	scanf("%d",&n);
	int tmp;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),t[a[i]]=1;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),t[b[i]]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[a[i]^b[j]])
			{
				ans++;
			}
		}
	}
	if(ans&1)printf("Koyomi\n");
	else printf("Karen\n");
	return 0;
}