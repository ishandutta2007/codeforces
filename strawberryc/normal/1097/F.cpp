#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5, M = 7005;

int n, q, miu[M], tot, pri[M];
bool mark[M];

std::bitset<M> times[N], fy[M];

void sieve()
{
	mark[0] = mark[miu[1] = 1] = 1;
	for (int i = 2; i <= 7000; i++)
	{
		if (!mark[i]) miu[pri[++tot] = i] = 1;
		for (int j = 1; j <= tot; j++)
		{
			if (i * pri[j] > 7000) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			else miu[i * pri[j]] = miu[i];
		}
	}
	for (int i = 1; i <= 7000; i++)
		for (int j = i; j <= 7000; j += i)
			fy[i][j] = miu[j / i];
}

int main()
{
	n = read(); q = read();
	sieve();
	int op, x, y, z;
	while (q--)
	{
		op = read(); x = read(); y = read();
		if (op == 1)
		{
			int S = sqrt(y);
			times[x] = 0;
			for (int i = 1; i <= S; i++)
			{
				if (y % i) continue;
				times[x][i] = times[x][y / i] = 1;
			}
		}
		else if (op == 2) z = read(), times[x] = times[y] ^ times[z];
		else if (op == 3) z = read(), times[x] = times[y] & times[z];
		else printf("%d", (times[x] & fy[y]).count() & 1);
	}
	return puts(""), 0;
}