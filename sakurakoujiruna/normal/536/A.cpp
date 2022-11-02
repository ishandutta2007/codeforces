#include <iostream>
using namespace std;

typedef long long intl;
typedef long double doublel;

intl num(int n, intl a, intl b)
{
	return a + (n - 1) * b;
}

intl sum(int n, intl a, intl b)
{
	return (num(1, a, b) + num(n, a, b)) * n / 2;
}

bool check(intl a, intl b, int l, int r, int t, int m)
{
	intl s = sum(r, a, b) - sum(l - 1, a, b);
	return (intl)t * m >= s && t >= num(r, a, b);
}

int main()
{
	ios :: sync_with_stdio(false);
	intl a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	while(n --)
	{
		int l, t, m;
		cin >> l >> t >> m;
		if(t < num(l, a, b))
			cout << -1 << '\n';
		else
		{
			int left = l, right = l + 1e6 + 3;
			while(left + 1 < right)
			{
				int mid = (left + right) / 2;
				if(check(a, b, l, mid, t, m))
					left = mid;
				else
					right = mid;
			}
			cout << left << '\n';
		}
	}
	return 0;
}