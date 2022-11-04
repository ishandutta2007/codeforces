#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (auto v : s)
	{
		if (v == 'U')
			++y;
		if (v == 'D')
			--y;
		if (v == 'R')
			++x;
		if (v == 'L')
			--x;
	}
	cout << n - abs(x) - abs(y) << endl;
}