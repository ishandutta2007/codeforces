#include <iostream>
using namespace std;

int main()
{
	char c;
	int a;
	cin>>c>>a;
	if(c == 'a' || c == 'h')
	{
		if(a == 1 || a == 8) cout<<3<<endl;
		else cout<<5<<endl;
	}
	else
	{
		if(a == 1 || a == 8) cout<<5<<endl;
		else cout<<8<<endl;
	}
	return 0;
}