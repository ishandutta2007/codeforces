#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 2e5 + 5, EI = 998244353, I2 = 499122177;

int n, m, fac[N], inv[N], ans, cnt, cnt0, cnt1, cnt_0, cnt_1, p2[N], i2[N],
posC, posCi, negC, negCi;
char s[N];

int C(int n, int m)
{
	if (m < 0 || m > n) return 0;
	return 1ll * fac[n] * inv[m] % EI * inv[n - m] % EI;
}

int main()
{
	int pos; char c; read(n); read(m);
	fac[0] = inv[0] = inv[1] = p2[0] = i2[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % EI,
		p2[i] = 2ll * p2[i - 1] % EI, i2[i] = 1ll * I2 * i2[i - 1] % EI;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * (EI - EI / i) * inv[EI % i] % EI;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % EI;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '?') cnt++;
		if ((i & 1) && s[i] == 'w') cnt0++;
		if ((i & 1) && s[i] != 'b') cnt_0++;
		if (!(i & 1) && s[i] == 'b') cnt1++;
		if (!(i & 1) && s[i] != 'w') cnt_1++;
	}
	for (int i = 0; i <= n; i++) if ((2 * i - n) % 4 == 0)
	{
		if (cnt0 + cnt1 > i || i > cnt_0 + cnt_1) continue;
		ans = (1ll * abs(2 * i - n) / 4 * C(cnt_0 + cnt_1
			- cnt0 - cnt1, i - cnt0 - cnt1) + ans) % EI;
	}
	std::cout << 1ll * ans * i2[cnt - 1] % EI << std::endl;
	for (int i = 0; i <= cnt_0 + cnt_1 - cnt0 - cnt1 &&
		i <= n / 2 - cnt0 - cnt1; i++)
		{
			int d = C(cnt_0 + cnt_1 - cnt0 - cnt1, i),
				di = 1ll * d * i % EI;
			posC = (posC + d) % EI; posCi = (posCi + di) % EI;
			if (i & 1) d = EI - d, di = EI - di;
			negC = (negC + d) % EI; negCi = (negCi + di) % EI;
		}
	while (m--)
	{
		read(pos);
		while ((c = getchar()) != 'w' && c != 'b' && c != '?');
		int mp = cnt_0 + cnt_1 - cnt0 - cnt1, mq = n / 2 - cnt0 - cnt1;
		if (pos & 1) cnt0 -= s[pos] == 'w', cnt0 += c == 'w',
			cnt_0 -= s[pos] != 'b', cnt_0 += c != 'b';
		else cnt1 -= s[pos] == 'b', cnt1 += c == 'b',
			cnt_1 -= s[pos] != 'w', cnt_1 += c != 'w';
		cnt -= s[pos] == '?'; cnt += c == '?';
		s[pos] = c;
		int np = cnt_0 + cnt_1 - cnt0 - cnt1, nq = n / 2 - cnt0 - cnt1;
		if (mp < np)
		{
			int t = C(mp, mq), u = mq & 1 ? EI - t : t;
			posCi = (2ll * posCi - 1ll * (mq + 1) * t % EI
				+ EI + posC) % EI;
			posC = (2ll * posC - t + EI) % EI;
			negCi = (1ll * (mq + 1) * u - negC + EI) % EI;
			negC = u;
		}
		else if (mp > np)
		{
			posC = 1ll * I2 * (C(np, mq) + posC) % EI;
			posCi = (1ll * (mq + 1) * C(np, mq) + posCi - posC + EI)
				% EI * I2 % EI;
			if (np)
			{
				int u = mq & 1 ? EI - C(np - 1, mq) : C(np - 1, mq);
				negC = u;
				negCi = (1ll * (mq + 1) * u - (np > 1 ? (mq & 1 ?
					EI - C(np - 2, mq) : C(np - 2, mq))
						: (mq >= 0)) + EI) % EI;
			}
			else negC = mq >= 0, negCi = 0;
		}
		if (mq < nq)
		{
			int d = C(np, nq), di = 1ll * d * nq % EI;
			posC = (posC + d) % EI; posCi = (posCi + di) % EI;
			if (nq & 1) d = EI - d, di = EI - di;
			negC = (negC + d) % EI; negCi = (negCi + di) % EI;
		}
		else if (mq > nq)
		{
			int d = C(np, mq), di = 1ll * d * mq % EI;
			posC = (posC - d + EI) % EI; posCi = (posCi - di + EI) % EI;
			if (mq & 1) d = EI - d, di = EI - di;
			negC = (negC - d + EI) % EI; negCi = (negCi - di + EI) % EI;
		}
		int resP = (1ll * nq * posC + (np ? 1ll * np * p2[np - 1] : 0)
			- posCi + EI) % EI,
			resN = (1ll * nq * negC + EI - (np == 1) - negCi + EI) % EI;
		resP = (1ll * resP - 1ll * nq * (p2[np] - posC + EI)
			% EI - posCi + EI + EI) % EI;
		resN = (1ll * resN - 1ll * nq * ((!np) - negC + EI)
			% EI - negCi + EI + EI) % EI;
		int res = nq & 1 ? 1ll * (resP - resN + EI) * I2 % EI
			: 1ll * (resP + resN) * I2 % EI;
		printf("%d\n", 1ll * i2[cnt] * res % EI);
	}
	return 0;
}