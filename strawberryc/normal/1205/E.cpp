#include <bits/stdc++.h>

const int N = 1e5 + 5, M = N << 1, rqy = 1e9 + 7;

int n, k, tot, ik, pk[N], pri[N], miu[N], a[M], b[M], ans;
bool mark[N];

std::vector<int> di[N];

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % rqy;
		a = 1ll * a * a % rqy;
		b >>= 1;
	}
	return res;
}

void sieve()
{
	mark[0] = mark[miu[1] = 1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) miu[pri[++tot] = i] = -1;
		for (int j = 1; j <= tot; j++)
		{
			if (1ll * i * pri[j] > n) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			miu[i * pri[j]] = -miu[i];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			di[j].push_back(i);
}

int main()
{
	std::cin >> n >> k;
	sieve(); ik = qpow(k, rqy - 2);
	pk[0] = 1;
	for (int i = 1; i <= n; i++) pk[i] = 1ll * pk[i - 1] * k % rqy;
	for (int i = n; i <= (n - 1 << 1); i++) a[i] = (n - 1 << 1) - i + 1;
	for (int p = 1; p < n; p++)
	{
		int l = (n - 1 << 1) / p;
		for (int i = 1; i <= l + 1; i++) b[i] = 0;
		for (int i = 0; i < di[p].size(); i++)
		{
			int d = di[p][i], m = (n + d - 1) / p;
			b[m] = (miu[p / d] + b[m] + rqy) % rqy;
			ans = (1ll * m * (m - 1) / 2 % rqy * pk[d]
				% rqy * (miu[p / d] + rqy) + ans) % rqy;
		}
		for (int i = l; i >= 1; i--) b[i] = (b[i] + b[i + 1]) % rqy;
		for (int i = 1; i <= l; i++)
			a[i * p] = (a[i * p] - 1ll * b[i] * (i - 1) % rqy + rqy) % rqy;
	}
	for (int i = n; i <= (n - 1 << 1); i++)
		ans = (1ll * a[i] * pk[i - n] + ans) % rqy;
	for (int i = 1; i <= n; i++) ans = 1ll * ans * ik % rqy;
	return std::cout << ans << std::endl, 0;
}