#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

const int B = 17;
const int MX = 1 << B;
const int mod = 1e9 + 7;
const int rev2 = (mod + 1) / 2;

int add(int a, int b)
{
	a += b;
	return a >= mod ? a - mod : a;
}
int mult(int a, int b)
{
	return 1LL * a * b % mod;
}
int sub(int a, int b)
{
	a -= b;
	return a < 0 ? a += mod : a;
}

vector<int> adamant(vector<int> x, bool rev)
{
	int n = x.size();
	for (int i = 0; i < B; ++i)
	{
		for (int j = 0; j < n; ++j)
			if ((j >> i & 1) == 0)
			{
				int j1 = j ^ (1 << i);
				int a = x[j], b = x[j1];
				x[j] = add(a, b);
				x[j1] = sub(a, b);
			}
	}
	if (rev)
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < B; ++j)
				x[i] = mult(x[i], rev2);
		}
	return x;
}

vector<int> upsets(vector<int> v)
{
	for (int j = 0; j < B; ++j)
		for (int i = 0; i < MX; ++i)
			if (!(i >> j & 1))
				v[i] = add(v[i], v[i ^ (1 << j)]);
	return v;
}

vector<int> rev(vector<int> v)
{
	for (int j = 0; j < B; ++j)
		for (int i = 0; i < MX; ++i)
			if (!(i >> j & 1))
				v[i] = sub(v[i], v[i ^ (1 << j)]);
	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	int sz;
	cin >> sz;
	vector<int> cnt(MX);
	for (int i = 0; i < sz; ++i)
	{
		int x;
		cin >> x;
		++cnt[x];
	}
	vector<int> fib(MX);
	fib[1] = 1;
	for (int i = 2; i < MX; ++i)
		fib[i] = add(fib[i - 1], fib[i - 2]);
	vector<int> cntab(MX);
	for (int i = 0; i < MX; ++i)
	{
		for (int j = i; j > 0; --j, j &= i)
			cntab[i] = add(cntab[i], mult(cnt[j], cnt[i ^ j]));
		cntab[i] = add(cntab[i], mult(cnt[i], cnt[0]));
	}
	vector<int> cntc = cnt;
	auto cntde = adamant(cnt, false);
	for (int i = 0; i < MX; ++i)
		cntde[i] = mult(cntde[i], cntde[i]);
	cntde = adamant(cntde, true);
	for (int i = 0; i < MX; ++i)
	{
		cntab[i] = mult(cntab[i], fib[i]);
		cntc[i] = mult(cntc[i], fib[i]);
		cntde[i] = mult(cntde[i], fib[i]);
	}
	cntab = upsets(cntab);
	cntc = upsets(cntc);
	cntde = upsets(cntde);
	for (int i = 0; i < MX; ++i)
		cntab[i] = mult(cntab[i], mult(cntc[i], cntde[i]));
	cntab = rev(cntab);
	int ans = 0;
	for (int i = 0; i < B; ++i)
		ans = add(ans, cntab[1 << i]);
	cout << ans << endl;

}