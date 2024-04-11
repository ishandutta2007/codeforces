#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	int mid = -1;
	for(int i = 0; i < s.size(); i ++)
		if(s[i] == '^')
			mid = i;
	ll left = 0, right = 0;
	for(int i = 0; i < s.size(); i ++)
		if(isdigit(s[i]))
		{
			if(i < mid)
				left += (s[i] - '0') * (mid - i);
			else
				right += (s[i] - '0') * (i - mid);
		}
	if(left == right)
		cout << "balance\n";
	else
		cout << (left > right ? "left" : "right") << '\n';
	return 0;
}