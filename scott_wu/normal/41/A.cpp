#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	string s, t;
	cin >> s >> t;
	
	if (s.length() != t.length())
	{
		cout << "NO\n";
		return 0;
	}
	
	for (int i = 0; i < s.length(); i++)
		if (s[i] != t[s.length()-1-i])
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}