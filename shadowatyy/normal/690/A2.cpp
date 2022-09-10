#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if (n%2)
	{
		cout<<(n-1)/2;
		return 0;
	}
	int pot2=1;
	for (int i=1; pot2*2<=n; pot2*=2);
	cout<<(n-pot2)/2;
	return 0;
}