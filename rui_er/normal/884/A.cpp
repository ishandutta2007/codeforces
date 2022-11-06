#include <iostream>
using namespace std;

int main()
{
	int n, t;
	cin>>n>>t;
	const int daytime = 86400;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		t -= daytime - a;
		if(t <= 0)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}