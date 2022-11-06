#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int s = 0;
	int k, b;
	k = 0;
	b = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s += a[i];
		if(a[i]&1) ++k;
		else ++b;
	}
	cout<<(s&1 ? k : b)<<endl;
	return 0;
}