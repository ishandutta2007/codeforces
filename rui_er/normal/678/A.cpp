#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int x = n + k - n % k;
/*	for(x=n+1;x<=k;x++)
	{
		if(k % x == 0)
		{
			break;
		}
	}*/
	cout<<x<<endl;
	return 0;
}