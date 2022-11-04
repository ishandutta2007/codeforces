#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	while (s.length() && s.back() == '0')
		s.pop_back();
	int cnt = 0;
	for (auto x : s)
		if (x == '0')
			++cnt;
	if (cnt > 5)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}