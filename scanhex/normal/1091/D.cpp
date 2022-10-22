#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
const int mod = 998244353;

#define div aentuassh

nagai pw(nagai a, nagai b)
{
	nagai ans = 1;
	while (b)
	{
		 if (b & 1)
			 (ans *= a) %= mod;
		 (a *= a) %= mod;
		 b >>= 1;
	}
	return ans;
}
nagai sum(nagai a, nagai b)
{
	if ((a += b) >= mod)
		return a - mod;
	return a;
}

int sub(int a, int b)
{
	 a -= b;
	 if (a < 0)
		 a += mod;
	 return a;
}

nagai diff(nagai a, nagai b)
{
	 if ((a -= b) < 0)
		 return a + mod;
	 return a;
}

nagai mult(nagai a, nagai b)
{
	 return a * b % mod;
}

nagai div(nagai a, nagai b)
{
	 return mult(a, pw(b, mod - 2));
}

vector<nagai> berlekamp(vector<int> mem)
{
	vector<nagai> p;
	vector<nagai> q;
	int i = 0;
	while (mem[i] == 0)
		++i;
	mem.erase(mem.begin(), mem.begin() + i);
	assert(mem.size() > 1);
	p.push_back(1);
	q.push_back(1);
	nagai qval = 1;
	for (int i = 0; i < mem.size(); ++i)
	{
		nagai kek = 0;
		for (int j = 0; j < p.size(); ++j)
			kek = sum(kek, mult(p[j], mem[i - j]));
		if (kek == 0)
			q.insert(q.begin(), 0);
		else
		{
			auto q1 = p;
			nagai old = qval;
			// p1 = p - qx * new/old
			auto p1 = p;
			auto mu = div(kek, old);
			for (int j = 0; j < q.size(); ++j)
			{
				if (j + 1 >= p1.size())
					p1.push_back(0);
				p1[j + 1] = diff(p1[j + 1], mult(q[j], mu));
			}
			qval = kek;
			p = p1, q = q1;
		}
	}
	return p;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i)
		fact[i] = mult(fact[i - 1], i);
	int ans = mult(n, fact[n]);
	int cur = 1;
	for (int i = 1; i < n; ++i)
	{
		cur = mult(cur, n - i);
//		ans = sub(ans, mult(cur, n - i - 1));
		ans = sub(ans, div(fact[n], fact[i]));
	}
	cout << ans << '\n';
	return 0;
}