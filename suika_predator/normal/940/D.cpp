#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int a[233333];
char b[233333];
int l=-1000000000,r=1000000000;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf(" %s",b+1);
	for(int i=5;i<=n;i++)
	{
		int lmin=min(min(min(a[i],a[i-1]),min(a[i-2],a[i-3])),a[i-4]),lmax=max(max(max(a[i],a[i-1]),max(a[i-2],a[i-3])),a[i-4]);
		//cout<<i<<' '<<lmin<<' '<<lmax<<' '<<b[i]<<' '<<b[i-1]<<endl;
		if(b[i]=='0'&&b[i-1]=='1')r=min(r,lmin-1);
		if(b[i]=='1'&&b[i-1]=='0')l=max(l,lmax+1);
	}
	printf("%d %d\n",l,r);
	return 0;
}