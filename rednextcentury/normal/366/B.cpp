#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <cmath>
# include <iomanip>
using namespace std;
int a[100000];
int ans(int i,int k,int n)
{
	int h=0;
	int x=i;
	int y=0;
	while(true)
	{
		h+=a[x];
		y++;
		if (y==n/k)
			break;
		x+=k;
		if (x>=n)
			x-=n;
	}
	return h;
}
int main()
{
	long long n;
	cin>>n;
	long long k;cin>>k;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l=1000000000;
	int u=1000000000;
	for (int i=0;i<k;i++)
	{
		int p=ans(i,k,n);
		if (p<u)
		{
			l=i;
			u=p;
		}
	}
	cout<<l+1<<endl;
}