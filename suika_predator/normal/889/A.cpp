#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int t[233333],f[233333];
int main()
{
	scanf("%d",&n);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		if(f[t[i]])ans++;
		else f[t[i]]=1;
	}
	printf("%d\n",ans);
	return 0;
}