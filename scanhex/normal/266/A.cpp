#include <iostream>
#include <string>
#define ll long long

using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str;  
	char cur = str[0];
	int ans = 0;
	int s = 1;  
	for (int i = 1; i < n; ++i)
	{           
		char c = str[i];
		if (c != cur)
		{                
			ans += s - 1;
			s = 0;
			cur = c;
		}            
		++s;
	}
	cout << ans + s - 1; 
}