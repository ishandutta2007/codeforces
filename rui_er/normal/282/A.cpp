#include <iostream>
#include <string>
using namespace std;

int x;

int main()
{
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		cin>>s;
		if(s[0] == '-' || s[1] == '-') x--;
		else x++;
	}
	cout<<x<<endl;
	return 0;
}