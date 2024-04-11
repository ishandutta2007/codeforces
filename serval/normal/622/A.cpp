#include <iostream>
using namespace std;
long long n,t;
int main()
{
	cin>>n;
	t=1;
	while (n>t)
	{
		n-=t;
		t++;
	}
	cout<<n;
	return 0;
}