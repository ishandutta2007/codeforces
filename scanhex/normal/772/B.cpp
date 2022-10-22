#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

struct pt
{
	nagai x, y;
	pt(nagai x, nagai y)
		: x(x), y(y)
	{}
	pt operator -(pt b)
	{
		return pt(x - b.x, y - b.y);
	}
	nagai operator %(pt b)
	{
		return x * b.y - y * b.x;
	}
	double len()
	{
		return hypot(x, y);
	}
	pt(){}
};

double solve(vector<pt> mem)
{
	double mn = 1000000000000.0;
	for (int i = 0; i < 3; ++i)
	{
		int j = (i + 1) % 3;
		int k = (j + 1) % 3;
		mn = min(mn, abs((mem[i] - mem[j]) % (mem[i] - mem[k]) / (mem[k] - mem[j]).len()));
	}
	return mn;
}

int main()
{
	int n;
	cin >> n;
	vector<pt> kek(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> kek[i].x >> kek[i].y;
	}
	double ans = 1000000000000.0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int k = (i + 1) % n;
			if (j == i || j == k)
				continue;
			vector<pt> oe;
			ans = min(ans, solve({kek[i], kek[j], kek[k]}));
		}
	}
	cout.precision(30);
	cout << ans / 2 << endl;
}