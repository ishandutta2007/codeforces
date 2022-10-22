#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

#define pow othu

const nagai mod = 1e9 + 7;

void md(nagai& x)
{
	if (x >= mod)
		x -= mod;
}


nagai pow(nagai a, nagai b)
{
	if (b < 0)
		b += mod - 1;
	nagai ans = 1;
	while (b)
	{
		if (b & 1)
			(ans *= a) %= mod;
		b >>= 1;
		(a *= a) %= mod;
	}
	return ans;
}

nagai inv(nagai x)
{
	return pow(x, mod - 2);
}

// T(n,k) = Sum_{j = 0..n} (-1)^(n+k)*(-2)^(n-j)*Stirling2(n,j)*Stirling1(j,k). 

int main()
{
	int n, k;
	cin >> n >> k;
	/*
	vector<vector<nagai>> st1(k + 1, vector<nagai>(k + 1)), st2 = st1;
	st1[0][0] = st2[0][0] = 1;
	for (int i = 1; i <= k; ++i)
		for (int j = 0; j <= k; ++j)
			if (j > 0)
				st1[i][j] = ((i - 1) * st1[i - 1][j] + st1[i - 1][j - 1]) % mod,
					st2[i][j] = (j * st2[i - 1][j] + st2[i - 1][j - 1]) % mod;
			else
				st1[i][j] = ((i - 1) * st1[i - 1][j]) % mod,
					st2[i][j] = j * st2[i - 1][j] % mod;
	vector<nagai> coef(k + 1);
	for (int i = 0; i <= k; ++i) // k
	{
		for (int j = 0; j <= k; ++j) // j
		{
			nagai mem = (k + i) % 2 == 0 ? 1 : -1;
			(mem *= pow(mod - 2, k - j)) %= mod;
			(mem *= st2[k][j]) %= mod;
			(mem *= st1[j][i]) %= mod;
			coef[i] += mem;
			if (coef[i] < 0)
				coef[i] += mod;
			if (coef[i] >= mod)
				coef[i] -= mod;
		}
	}
	for (auto& x : coef)
		cerr << x << ' ';
	cerr << endl;
	*/
	int cnt = k + 3;
	vector<nagai> xs, ys;
	nagai ansich = 0;
	vector<nagai> pw(20000);
	for (int i = 0; i < pw.size(); ++i)
		pw[i] = pow(i, k);
	vector<nagai> in(20000);
	for (int i = 0; i < pw.size(); ++i)
		in[i] = inv(i);
	for (int n = k; n < k + cnt; ++n)
	{
		nagai ans = 0;
		nagai curc = 1;
		for (int i = 0; i <= n; ++i)
		{
			(ans += pw[i] * curc) %= mod;
			if (i < n)
			{
				(curc *= in[i + 1]) %= mod;
				(curc *= n - i) %= mod;
			}
		}
		(ans *= inv(pow(2, n - k))) %= mod;
		xs.push_back(n);
		ys.push_back(ans);
	}
	for (int i = 0; i < cnt; ++i)
	{
		nagai up = 1;
		for (int j = 0; j < cnt; ++j)
		{
			if (j != i)
				(up *= n - xs[j]) %= mod;
		}
		nagai down = 1;
		for (int j = 0; j < cnt; ++j)
			if (j != i)
				(down *= (xs[i] - xs[j])) %= mod;
		(up *= inv(down)) %= mod;
		(ansich += up * ys[i]) %= mod;
	}
	if (ansich < 0)
		ansich += mod;
	(ansich *= pow(2, n - k)) %= mod;
	cout << ansich << endl;
}