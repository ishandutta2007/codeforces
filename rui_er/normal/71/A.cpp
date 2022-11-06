#include <iostream>
#include <string> 
using namespace std;

int main()
{
	int n;
	cin>>n;
	string a;
	while(n--)
	{
		cin>>a;
		int len = a.size();
		if(len <= 10) cout<<a<<endl;
		else cout<<a[0]<<len-2<<a[len-1]<<endl;
	}
	return 0;
}