#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin>>s1;
	cin>>s2;
	int len = s1.size();
	bool a, b;
	bool ans;
	for(int i=0;i<len;i++)
	{
		a = s1[i] - '0';
		b = s2[i] - '0';
		ans = a xor b;
		cout<<ans;
	}
	return 0;
}