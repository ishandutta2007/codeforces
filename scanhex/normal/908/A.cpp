#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	set<char> vow = {'a', 'e', 'i', 'o', 'u'};
	set<char> even = {'0', '2', '4', '6', '8'};
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (vow.count(s[i]))
			++cnt;
		if ('0' <= s[i] && s[i] <= '9' && !even.count(s[i]))
			++cnt;
	}
	cout << cnt << endl;
}