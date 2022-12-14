#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <cmath>
# include <iomanip>
using namespace std;
int a[100][4];
int main()
{
	long long n;
	cin>>n;
	for (int i=0;i<4;i++)
	{
		for (int x=0;x<4;x++)
		{
			cin>>a[i][x];
		}
	}
	int l=1000000;
	int loc;
	int first;
	for (int i=0;i<4;i++)
	{
		int ans=min(a[i][0],a[i][1])+min(a[i][2],a[i][3]);
		if (ans<l)
		{
			l=ans;
			loc=i;
			first=min(a[i][0],a[i][1]);
		}
	}
	if (l<=n)
		cout<<loc+1<<" "<<first<<" "<<n-first<<endl;
	else
		cout<<-1<<endl;
}