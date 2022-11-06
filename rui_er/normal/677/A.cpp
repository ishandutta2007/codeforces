#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int a;
	int c = 0;
	while(n--)
	{
		cin>>a;
		if(a > k) c++;
		c++;
	}
	cout<<c<<endl;
	return 0;
}