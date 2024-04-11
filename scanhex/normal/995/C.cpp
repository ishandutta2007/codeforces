#include <bits/stdc++.h>

using namespace std;
using db = long double;
using cp = complex<db>;

istream& operator >>(istream& a, cp& b)
{
	db x, y;
	a >> x >> y;
	b.real(x);
	b.imag(y);
	return a;
}

db cross(cp a, cp b)
{
	return a.real() * b.imag() - b.real() * a.imag();
}

bool upper(cp x)
{
	return x.imag() > 0 || (x.imag() == 0 && x.real() < 0);
}

db sqr(db x)
{
	return x * x;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<cp> mem(n);
	vector<bool> inv(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> mem[i];
		if (!upper(mem[i]))
			mem[i] = -mem[i], inv[i] = true;
	}
	cp sum = accumulate(mem.begin(), mem.end(), cp());
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	auto cmp = [&](int a, int b)
			{
			return cross(mem[a], mem[b]) > 0;
			};
	sort(ord.begin(), ord.end(), cmp);
	int L = -1, R = n;
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		if (cross(mem[ord[M]], sum) > 0)
			L = M;
		else
			R = M;
	}
	for (auto& x : mem)
		x *= 2;
	while (true)
	{
		random_shuffle(ord.begin() + R, ord.end());
		random_shuffle(ord.begin(), ord.begin() + R);
		int ind = R;
		int i = ind;
		int j = ind - 1;
		if (j == -1)
			j = n - 1;
		cp cur = 0;
		vector<bool> ans(n);
		double eps = 1e-7;
		bool ok = true;
		while (true)
		{
			//cerr << cur << ' ' << sum << '\n';
			if (abs(cur - sum) <= 1500000 - 100)
			{
				break;
			}
			if (cross(cur, sum) >= 0 && !ans[ord[i]])
				cur += mem[ord[i]], ans[ord[i++]] = 1;
			else if (!ans[ord[j]])
				cur += mem[ord[j]], ans[ord[j--]] = 1;
			else
			{
				ok = false;
				break;
			}
			if (i == n)
				i = 0;
			if (j < 0)
				j = n - 1;
		}
		if (!ok)
			continue;
		cp ansich = 0;
		for (int i = 0; i < n; ++i)
		{
			if (ans[i] ^ inv[i])
				cout << 1 << ' ';
			else
				cout << -1 << ' ';
			if (ans[i])
				ansich += mem[i];
			else
				ansich -= mem[i];
		}
		ansich /= (db)2;
		cout << '\n';
		break;
	}
	//cerr << ansich << ' ' << abs(ansich) << '\n';
}