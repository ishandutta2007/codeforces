#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

const int MX = 1 << 19;

int t[2 * MX];

int gcd(int a, int b)
{
	while (b)
		a = a % b, swap(a, b);
	return a;
}

int n = MX;

void mod(int i, int v)
{
	i += n;
	t[i] = v;
	while (i > 1)
		t[i >> 1] = gcd(t[i], t[i ^ 1]), i >>= 1;
}

int get(int l, int r)
{
	int ans = 0;
	l += n;
	r += n;
	while (l < r)
	{
		if (l & 1)
			ans = gcd(ans, t[l++]);
		if (r & 1)
			ans = gcd(ans, t[--r]);
		l >>= 1, r >>= 1;
	}
	return ans;
}

int getfibad(int x, int l, int r, int ql, int val)
{
	if (r <= ql || t[x] % val == 0)
		return -1;
	if (r - l == 1)
		return l;
	int m = l + r >> 1;
	int ans = getfibad(2 * x, l, m, ql, val);
	if (ans != -1)
		return ans;
	return getfibad(2 * x + 1, m, r, ql, val);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		mod(i, x);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			--l;
			int L = getfibad(1, 0, MX, l, x);
			if (L == -1 || get(L + 1, r) % x == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			int i, v;
			cin >> i >> v;
			--i;
			mod(i, v);
		}
	}
}