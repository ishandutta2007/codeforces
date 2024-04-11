#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, ans;
	map<char, int> ct;
	map<char, int>::iterator it;

	cin >> s;
	for (auto x : s)
	{
		if(ct.count(x)) ct[x]++;
		else ct[x] = 1;
	}
	ans = "No";
	if(ct.size() == 2)
	{
		ans = "Yes";
		for(it = ct.begin(); it != ct.end(); it++)
		{
			if(it->second < 2) ans = "No";
		}
	}
	if(ct.size() == 3)
	{
		for(it = ct.begin(); it != ct.end(); it++)
		{
			if(it->second >= 2) ans = "Yes";
		}
	}
	if(ct.size() == 4)
	{
		ans = "Yes";
	}
	cout << ans;
}