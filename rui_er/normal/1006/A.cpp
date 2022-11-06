#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		cout<<(k % 2 == 0 ? k - 1 : k)<<" ";
	}
	return 0;
}