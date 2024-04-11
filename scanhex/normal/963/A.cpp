#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

#define pow otuaheotu

const int mod = 1e9 + 9;

int add(int a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int mult(int a, int b)
{
	return 1LL * a * b % mod;
}

int pw(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = mult(ans, a);
		b >>= 1;
		a = mult(a, a);
	}
	return ans;
}

int inv(int x)
{
	return pw(x, mod - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int nk = (n + 1) / k;
	int x = 0;
	string s;
	cin >> s;
	int cur = pw(a, n);
	int inva = inv(a);
	for (int i = 0; i < k; ++i)
	{
		int si = s[i] == '+' ? 1 : -1;
		if (si < 0)
			si += mod;
		x = add(x, mult(si, cur));
		cur = mult(cur, b);
		cur = mult(cur, inva);
	}
	int mem = mult(pw(b, k), inv(pw(a, k)));
	int neg1 = mod - 1;
	if (mem == 1)
	{
		cout << mult(x, nk) << '\n';
		return 0;
	}
	int ans = mult(x, mult(add(pw(mem, nk), neg1), inv(add(mem, neg1))));
	cout << ans << '\n';
	return 0;
}