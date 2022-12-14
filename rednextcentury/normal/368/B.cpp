#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <queue>
# include <iomanip>
using namespace std;
int a[1000000];
int b[1000000];
int c[1000000];
int d[1000000];
bool p[1999999];
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for (int i=0;i<m;i++)
	{
		cin>>b[i];
		b[i]--;
	}
	
	for (int i=0;i<n;i++)
	{
		if (c[a[i]]>0 && p[a[i]]==0)
		{
			d[0]++;
			p[a[i]]=1;
		}
	}
	for (int i=1;i<n;i++)
	{
		if (c[a[i-1]]==1)
			d[i]=d[i-1]-1;
		else
			d[i]=d[i-1];
		c[a[i-1]]--;
	}
	for (int i=0;i<m;i++)
	{
		cout<<d[b[i]]<<endl;;
	}
}