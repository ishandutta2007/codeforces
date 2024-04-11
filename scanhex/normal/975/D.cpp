#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;
const nagai mod = 999239239;

nagai mult(nagai a, nagai b)
{
	return a * b % mod;
}

nagai pw(nagai a, nagai b)
{
	nagai ans = 1;
	while (b)
	{
		if (b & 1)
			ans = mult(ans, a);
		a = mult(a, a);
		b >>= 1;
	}
	return ans;
}

#define div aoetuhoe

nagai div(nagai a, nagai b)
{
	return mult(a, pw(b, mod - 2));
}

void md(nagai& a)
{
	a %= mod;
	if (a < 0)
		a += mod;
}


int main()
{
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> x(n), vx(n), vy(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> vx[i] >> vy[i];
	nagai ans = 0;
	map<nagai, int> cnt;
	map<pair<nagai, nagai>, int> cnt1;
	for (int i = 0; i < n; ++i)
	{
		nagai y = 1LL * a * x[i] + b;
		nagai x1 = x[i] + vx[i];
		nagai y1 = y + vy[i];
		md(x1);
		md(y1);
		nagai dst = mult(x1, a) - y1 + b;
		md(dst);
		cnt1[{vx[i], vy[i]}]++;
		cnt[dst]++;
	}
	for (auto& x : cnt)
	{
		ans += 1LL * x.second * (x.second - 1);
	}
	for (auto& x : cnt1)
		ans -= 1LL * x.second * (x.second - 1);
	cout << ans << '\n';
}