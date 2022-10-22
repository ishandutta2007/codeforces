#include <iostream>
#include <string>
#define ll long long

using namespace std;

int main()
{                       
	string s;
	cin >> s;
	int c = 0;
	char cur = 7;
	for (int i = 0; i < s.length(); ++i) 
	{
		if (s[i] == cur)
			++c;
		else 
		{
			c = 1;
			cur = s[i];
		} 
		if (c >= 7)
		{
			cout << "YES";
			return 0;
		} 
	}
	cout << "NO";
}