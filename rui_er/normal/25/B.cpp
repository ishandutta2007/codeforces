#include <iostream>
using namespace std;

int main()
{
	int n;
	string s;
	cin>>n>>s;
	if(n&1)
	{
		for(int i=0;i<n-3;i+=2) cout<<s[i]<<s[i+1]<<'-';
		cout<<s[n-3]<<s[n-2]<<s[n-1];
	}
	else
	{
		for(int i=0;i<n-2;i+=2) cout<<s[i]<<s[i+1]<<'-';
		cout<<s[n-2]<<s[n-1];
	}
	cout<<endl;
	return 0;
}