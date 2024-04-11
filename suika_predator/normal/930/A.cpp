#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,p;
int dep[233333],cnt[233333];
int main()
{
	scanf("%d",&n);
	dep[1]=1;cnt[1]++;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		dep[i]=dep[p]+1;
		cnt[dep[i]]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=cnt[i]&1;
	printf("%d\n",ans);
	return 0;
}