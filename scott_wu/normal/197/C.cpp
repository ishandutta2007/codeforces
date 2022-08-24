#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string ans = "";
	int loc = 0;
	for (int i = 25; i >= 0; i--)
	{
		for (int j = loc; j < s.length(); j++)
			if (s[j] == (char) ('a' + i))
			{
				ans += s[j];
				loc = j;	
			}
	}
	cout << ans << "\n";
}