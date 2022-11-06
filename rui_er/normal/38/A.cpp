#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int t[n];
	for(int i=1;i<n;i++) cin>>t[i];
	int a, b;
	cin>>a>>b;
	if(a >= b) cout<<0<<endl;
	else
	{
		int sum = 0;
		while(a < b) sum += t[a++];
		cout<<sum<<endl;
	}
	return 0;
}