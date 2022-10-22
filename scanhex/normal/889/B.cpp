#include <bits/stdc++.h>

using namespace std;

void fail()
{
	cout << "NO" << endl;
	exit(0);
}

int main()
{
	int n; 
	cin >> n;
	vector<int> bef(26, -1), aft(26, -1);
	vector<bool> used(26, true);
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (auto& ch : s)
			ch -= 'a', used[ch] = false;
		for (int i = 0; i < s.size() - 1; ++i)
		{
			if (s[i + 1] == s[i])
				fail();
			if (aft[s[i]] != -1 && aft[s[i]] != s[i + 1])
				fail();
			aft[s[i]] = s[i + 1];
			if (bef[s[i + 1]] != -1 && bef[s[i + 1]] != s[i])
				fail();
			bef[s[i + 1]] = s[i];
		}
	}
	vector<string> strs;
	for (int i = 0; i < 26; ++i)
	{
		if (used[i])
			continue;
		int j = i;
		int cnt = 0;
		while (bef[j] != -1)
		{
			if (++cnt > 30)
				fail();
			j = bef[j];
		}
		string s1;
		while (j != -1)
			s1.push_back(j + 'a'), used[j] = true, j = aft[j];
		strs.push_back(s1);
	}
	sort(strs.begin(), strs.end());
	for (auto x : strs)
		cout << x;
	cout << endl;
}