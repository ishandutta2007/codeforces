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
	int k;
	string str;
	
	cin >> k >> str;
	
	int nval[26];
	for (int i = 0; i < 26; i++)
		nval[i] = 0;
	
	for (int i = 0; i < str.length(); i++)
		nval[str[i]-'a']++;
	
	bool check = true;
	for (int i = 0; i < 26; i++)
		if (nval[i] % k)
			check = false;
	
	if (!check)
	{
		cout << "-1\n";
		return 0;
	}
	
	string ans = "";
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < nval[i] / k; j++)
			ans += (char) ('a' + i);
	string res = "";
	for (int i = 0; i < k; i++)
		res += ans;
	cout << res << "\n";
	return 0;
}