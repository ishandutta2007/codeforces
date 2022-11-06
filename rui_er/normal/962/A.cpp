#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum += a[i];
	}
	int cur = 0;
	for(int i=0;i<n;i++)
	{
		cur += a[i];
		if(2 * cur >= sum)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}