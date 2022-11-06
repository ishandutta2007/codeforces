#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	cin>>a[0]>>a[1]>>a[2];
	int k = (a[0] % 2 + a[1] % 2 + a[2] % 2) / 2;
	for(int i=3;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
		if(a[i] % 2 != k)
		{
			cout<<(i+1)<<endl;
			return 0;
		}
	return 0;
}