#include <iostream>
#include <map>
# include <stdio.h>
# include <algorithm>
# include <string>
# include <queue>
# include <iomanip>
using namespace std;
int a[10000];
int main()
{
	int n,d;
	cin>>n>>d;
	long long m;
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cin>>m;
	long long ans=0;
	for (int i=0;i<m;i++)
	{
		if (i<n)
		ans+=a[i];
		else
			ans-=d;
	}
	cout<<ans<<endl;
}