#include <iostream>
using namespace std;

int main()
{
	int t, s, x;
	cin>>t>>s>>x;
	if(x < t)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	x -= t;
	if(x % s == 0 || x % s == 1 && x != 1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
	return 0;
}