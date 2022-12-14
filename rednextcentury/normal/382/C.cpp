# include <iostream>
# include <string>
# include <algorithm>
# include <cmath>
# include <queue>
# include <stack>
# include <map>
using namespace std;
long long a[100000];
long long d[100000];
int main()
{
	long long n;
	cin>>n;
	map<long long,long long> m;
	int ds=0;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for (int i=1;i<n;i++)
	{
		if (++m[a[i]-a[i-1]]==1)
			d[ds++]=a[i]-a[i-1];
	}
	if (ds>2)
		cout<<0<<endl;
	else if (ds==0)
		cout<<-1<<endl;
	else if (ds==1)
	{
		if (d[0]==0)
		{
			cout<<1<<endl;
			cout<<a[0]<<endl;
		}
		else if (n==2)
		{
			if ((a[1]-a[0])%2!=0)
			{
				cout<<2<<endl;
				cout<<a[0]-d[0]<<" "<<a[n-1]+d[0]<<endl;
			}
			else
			{
				cout<<3<<endl;
				cout<<a[0]-d[0]<<" "<<a[0]+d[0]/2<<" "<<a[1]+d[0]<<endl;
			}
		}
		else
		{
				cout<<2<<endl;
				cout<<a[0]-d[0]<<" "<<a[n-1]+d[0]<<endl;
		}
	}
	else if (ds==2)
	{
		if ((d[1]==2*d[0] || d[0]==2*d[1]) && m[max(d[0],d[1])]==1)
		{
			cout<<1<<endl;
			for (int i=1;i<n;i++)
			{
				if (a[i]-a[i-1]==max(d[0],d[1]))
				{
					cout<<a[i-1]+min(d[0],d[1])<<endl;
				}
			}
		}
		else
			cout<<0<<endl;
	}
}