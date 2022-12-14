#include <iostream>
#include <map>
# include <queue>
# include <algorithm>
using namespace std;
int a[100000];
int main()
{
	int n,k;
	cin>>n>>k;
	int h=n-1-k;
	if ( n==k)
		cout<<-1<<endl;
	else
	{
		if (h%2!=0)
		{
			a[0]=n;
			a[n-1]=1;
			h--;
			for (int i=1;i<n-2;i+=2)
			{
				if (h==0)
					break;
				h-=2;
				a[i]=i+2;
				a[i+1]=i+1;
			}
			if (h!=0)
				cout<<-1<<endl;
		}
		else
		{
			for (int i=1;i<n-1;i+=2)
			{
				if (h==0)
					break;
				h-=2;
				a[i]=i+2;
				a[i+1]=i+1;
			}
			if (h!=0)
				cout<<-1<<endl;
		}
		for (int i=0;i<n;i++)
		{
			if (a[i]==0)
				cout<<i+1;
			else
				cout<<a[i];
			if (i<n-1)
				cout<<" ";
		}
		cout<<endl;
	}
}