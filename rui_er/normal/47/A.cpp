#include <iostream>
using namespace std;

int sigma[51] = {0, 1, 3};

int ans(int k);

int main()
{
	int n;
	cin>>n;
	for(int i=50;i>=1;i--)
	{
		int c = ans(i);
		if(c == n)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		if(c < n)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	return 0;
}

int ans(int k)
{
	if(sigma[k] != 0) return sigma[k];
	return sigma[k] = ans(k-1) + k;
}