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
	bool seen[26];
	for (int i = 0; i < 26; i++)
		seen[i] = false;
	int ans = 0;
	
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (!seen[str[i] - 'a'])
		{
			ans++;
			seen[str[i]-'a'] = true;
		}
	}
	if (ans % 2) cout << "IGNORE HIM!\n";
	else cout << "CHAT WITH HER!\n";
}