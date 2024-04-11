#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5, ZZQ = 1e9 + 7;

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % ZZQ;
		a = 1ll * a * a % ZZQ;
		b >>= 1;
	}
	return res;
}

int n, f[N], miu[N], tot, pri[N], inv[N], wt[N], num[N], res[N], ans;
bool mark[N];
std::vector<int> divi[N], cont[N];

int solve(int n, int m)
{
	int tt = divi[m].size(), res = 0;
	for (int i = 0; i < tt; i++)
	{
		int x = divi[m][i];
		res += miu[x] * (n / x);
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
			else miu[i * pri[j]] = -miu[i];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			divi[j].push_back(i);
	for (int i = 1; i <= n;)
	{
		int nxt = n / (n / i);
		for (int j = 1; j <= n / i; j++) res[j] = solve(n / i, j);
		for (int j = i; j <= nxt; j++)
			for (int k = j; k <= n; k += j)
				cont[k].push_back(res[k / j]);
		i = nxt + 1;
	}
}

int main()
{
	n = read();
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	sieve();
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		int tt = divi[i].size();
		for (int j = 0; j < tt; j++)
			wt[j + 1] = 1ll * inv[n] * cont[i][j] % ZZQ, num[j + 1] = divi[i][j];
		int qt = qpow((1 - wt[tt] + ZZQ) % ZZQ, ZZQ - 2);
		for (int j = 1; j < tt; j++) wt[j] = 1ll * wt[j] * qt % ZZQ;
		f[i] = qt;
		for (int j = 1; j < tt; j++)
			f[i] = (1ll * wt[j] * f[num[j]] + f[i]) % ZZQ;
	}
	for (int i = 1; i <= n; i++)
		ans = (1ll * inv[n] * f[i] + ans) % ZZQ;
	std::cout << ans << std::endl;
	return 0;
}

//