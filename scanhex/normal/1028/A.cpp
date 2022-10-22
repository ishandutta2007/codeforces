#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int sx = 0, sy = 0;
	int cntx = 0, cnty = 0;
	for (int i = 0; i < n; ++i)
	{
		 string s;
		 cin >> s;
		 for (int j = 0; j < m; ++j)
			 if (s[j] == 'B')
				 sx += i, sy += j, ++cntx;
	}
	cout << sx / cntx + 1 << ' ' << sy / cntx + 1 << '\n';
	return 0;
}