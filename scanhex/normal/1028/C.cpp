#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b = a, c = a, d = a;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> x1 = a, y1 = b, x2 = c, y2 = d;
	for (int i = 0; i + 1 < n; ++i)
	{
		x1[i + 1] = max(x1[i], a[i + 1]);
		y1[i + 1] = max(y1[i], b[i + 1]);
		x2[i + 1] = min(x2[i], c[i + 1]);
		y2[i + 1] = min(y2[i], d[i + 1]);
	}
	auto z1 = a, t1 = b, z2 = c, t2 = d;
	for (int i = n - 1; i > 0; --i)
	{
		z1[i - 1] = max(z1[i], a[i - 1]);
		t1[i - 1] = max(t1[i], b[i - 1]);
		z2[i - 1] = min(z2[i], c[i - 1]);
		t2[i - 1] = min(t2[i], d[i - 1]);
	}
	int oo = 2e9;
	for (int i = 0; i < n; ++i)
	{
		int lex1 = -oo, ley1 = -oo, lex2 = oo, ley2 = oo;
		if (i > 0)
			lex1 = x1[i - 1], ley1 = y1[i - 1], lex2 = x2[i - 1], ley2 = y2[i - 1];
		if (i < n - 1)
		{
			lex1 = max(lex1, z1[i + 1]);
			ley1 = max(ley1, t1[i + 1]);
			lex2 = min(lex2, z2[i + 1]);
			ley2 = min(ley2, t2[i + 1]);
		}
		if (lex1 <= lex2 && ley1 <= ley2)
		{
			 cout << lex1 << ' ' << ley1 << '\n';
			 exit(0);
		}
	}
	return 0;
}