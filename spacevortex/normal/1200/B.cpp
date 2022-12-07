#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=210;
int T,n,m,K,bz;
int h[N];
int main()
{
	int i,sum;
	T=rd();
	while(T--)
	{
		n=rd();m=rd();K=rd();
		for(i=1;i<=n;i++) h[i]=rd();
		sum=m;
		for(i=1;i<n;i++)
		{
			bz=max(h[i+1]-K,0);
			sum+=h[i]-bz;
			if(sum<0)
			{
				break;
			}
		}
		if(i==n) puts("YES");
		else puts("NO");
	}
	return 0;
}