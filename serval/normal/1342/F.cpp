#include <cstdio>

using namespace std;

const int N = 15;
const int oo = 1 << 30;

int n;
int a[N + 1], s[1 << N];
int mask[N + 1];
int f[N + 1][N + 1][1 << N];
int fs[N + 1][N + 1][1 << N];
int fp[N + 1][N + 1][1 << N];
int ans, ansp;
int v[N + 1], pos[N + 1];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		mask[i] = (1 << i) - 1;
	s[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[1 << i - 1] = a[i];
	}
	for (int i = 1; i < (1 << n); i++)
		if (i ^ (i & -i))
			s[i] = s[i ^ (i & -i)] + s[i & -i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k < (1 << n); k++)
				f[i][j][k] = oo;
	f[0][0][0] = 0;
	ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k < (1 << n); k++)
				if (f[i][j][k] < oo)
				{
					int b = mask[n] ^ k;
					for (int c = b; c; c = (c - 1) & b)
						if ((mask[n] ^ mask[j]) & c)
							if (s[c] > f[i][j][k])
							{
								int p = __builtin_ctz((mask[n] ^ mask[j]) & c) + 1;
								if (s[c] < f[i + 1][p][k | c])
								{
									f[i + 1][p][k | c] = s[c];
									fs[i + 1][p][k | c] = c;
									fp[i + 1][p][k | c] = j;
								}
							}
				}
			if (f[i][j][mask[n]] < oo)
			{
				ans = i;
				ansp = j;
			}
		}
	printf("%d\n", n - ans);
	for (int i = 1; i <= n; i++)
		pos[i] = i;
	int anss = mask[n];
	for (int i = ans; i; i--)
	{
		v[i] = fs[i][ansp][anss];
		for (int j = 1; j <= n; j++)
			if ((1 << j - 1) & v[i])
				if (j != ansp)
				{
					printf("%d %d\n", pos[j], pos[ansp]);
					for (int k = j; k <= n; k++)
						pos[k]--;
				}
		ansp = fp[i][ansp][anss];
		anss ^= v[i];
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}