#include <iostream>
#include <string>
#include <vector>
#define ll long long 
using namespace std;
int main() 
{                  
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; ++i)
	{     	
		getline(cin, s);
		if (s.length() <= 10)
			cout << s << endl;
		else
			cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;	
	}
}