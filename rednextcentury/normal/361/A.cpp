#include <iostream>
#include <map>
# include <queue>
# include <string>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			if (i==x)
				cout<<k;
			else
				cout<<0;
			if (x<n-1)
				cout<<" ";
		}
		cout<<endl;
	}
}