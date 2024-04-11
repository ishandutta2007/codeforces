#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000010;
int a[maxn];
int b[maxn];
int l[maxn],r[maxn],c[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int maxv=0,maxp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxv)
		{
			maxv=a[i];
			maxp=i;
		}
	}
	for(int i=maxp;i<n;i++) b[i-maxp]=a[i];
	for(int i=0;i<=maxp;i++) b[i+n-maxp]=a[i];
	c[n]=0;
	for(int i=n-1;i>=0;i--)
	{
		r[i]=i+1;
		while(r[i]<n && b[i]>b[r[i]]) r[i]=r[r[i]];
		if(r[i]<n && b[i]==b[r[i]]) 
		{
			c[i]=c[r[i]]+1;
			r[i]=r[r[i]];
		}
	}
	for(int i=1;i<n;i++)
	{
		l[i]=i-1;
		while(l[i]>0 && b[i]>=b[l[i]]) l[i]=l[l[i]];
	}
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=c[i];
		if(l[i]==0 && r[i]==n) ans++;
		else ans+=2;
	}
	cout<<ans<<"\n";
	return 0;
}