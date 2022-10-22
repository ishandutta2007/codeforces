#include <bits/stdc++.h>

// 0830

const int N = 1e6 + 5, ZZQ = 1e9 + 7;

char s[N], t[N];
int a, b, c, d, n, ns, nt, l[N], r[N], fac[N], inv[N], cnt[2][2];

int C(int n, int m)
{
	if (n < m) return 0;
	return 1ll * fac[n] * inv[m] % ZZQ * inv[n - m] % ZZQ;
}

int calc(int n, int m, int k)
{
	if (!n) return !m && !k;
	if (!m) return !k;
	if (!k || k > n) return 0;
	return 1ll * C(k - 1, m - 1) * C(n - k - 1, m) % ZZQ;
}

int solve(int *num)
{
	if (num[1] == 0) return 0;
	int res = 0; num[0] = 0;
	cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
		{
			cnt[num[i - 1]][0]++;
			int rb = b - cnt[0][1], rc = c - cnt[1][0], rd = d - cnt[1][1] + rb;
			if (rb >= 0 && rc >= 0 && rd >= 0 && num[i] == 1)
			{
				if (rb == rc) res = (res + calc(n - i + 1, rb, rd)) % ZZQ;
				else if (rb == rc + 1)
					res = (1ll * res + calc(n - i + 2, rb, rd)
						- calc(n - i + 1, rb, rd) + ZZQ) % ZZQ;
			}
			cnt[num[i - 1]][0]--;
		}
		cnt[num[i - 1]][num[i]]++;
	}
	if (cnt[0][0] == a && cnt[0][1] == b && cnt[1][0] == c && cnt[1][1] == d)
		res = (res + 1) % ZZQ;
	return res;
}

int main()
{
	scanf("%s%s", s + 1, t + 1);
	std::cin >> a >> b >> c >> d; b++;
	n = a + b + c + d;
	ns = strlen(s + 1); nt = strlen(t + 1);
	if (ns > n || n > nt) return puts("0"), 0;
	if (ns < n)
	{
		l[1] = 1;
		for (int i = 2; i <= n; i++) l[i] = 0;
	}
	else for (int i = 1; i <= n; i++) l[i] = s[i] - '0';
	if (n < nt) for (int i = 1; i <= n; i++) r[i] = 1;
	else for (int i = 1; i <= n; i++) r[i] = t[i] - '0';
	for (int i = n; i; i--)
		if (l[i]) {l[i] = 0; break;}
		else l[i] = 1;
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= 1000000; i++) fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	for (int i = 2; i <= 1000000; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 2; i <= 1000000; i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
	std::cout << (solve(r) - solve(l) + ZZQ) % ZZQ << std::endl;
	return 0;
}