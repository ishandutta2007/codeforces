#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#define N 100005
using namespace std;
int n,a[N],b[N],c[N];
long long s0,s1;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",a+i),b[i]=a[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]==b[n-1])c[i]=b[0];
		else for(int j=0;j<n;j++)
		if(a[i]==b[j]){c[i]=b[j+1];break;}
	}
	for(int i=1;i<(1<<n)-1;i++)
	{
		s0=s1=0;
		for(int j=0;j<n;j++)
		if(i>>j&1)
		s0+=a[j],s1+=c[j];
		if(s0==s1)return puts("-1"),0;
	}
	for(int i=0;i<n;i++)
	printf("%d ",c[i]);
}