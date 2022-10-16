#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int N = 1 << 19;
const int mod = 998244353;
const int G = 3;
const int len = N;

int n, k, f;
int p[N], g[N], v[N];

int fpw(int b, int e)
{
	if (e == 0)
		return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1)
		ret = 1ll * ret * b % mod;
	return ret;
}

void init()
{
	for (int i = 0; (1 << i) < len; i++)
		for (int j = 0; j < len; j++)
			p[j] = (p[j] << 1) | ((j >> i) & 1);
}

void dft(int g[], int r = 1)
{
	for (int i = 0; i < len; i++)
		v[i] = g[p[i]];
	for (int i = 2; i <= len; i <<= 1)
	{
		int w = fpw(G, (mod - 1) / i);
		for (int j = 0; j < len; j += i)
		{
			int wn = 1;
			for (int k = 0; k < (i >> 1); k++)
			{
				int x = v[j + k];
				int y = 1ll * v[j + k + (i >> 1)] * wn % mod;
				v[j + k] = (x + y) % mod;
				v[j + k + (i >> 1)] = (x + mod - y) % mod;
				wn = 1ll * wn * w % mod;
			}
		}
	}
	if (r == -1)
	{
		int inv = fpw(len, mod - 2);
		for (int i = 0; i < len; i++)
			v[i] = 1ll * v[i] * inv % mod;
		for (int i = 1; i < (len >> 1); i++)
			swap(v[i], v[len - i]);
	}
	for (int i = 0; i < len; i++)
		g[i] = v[i];
}

void multi()
{
	dft(g);
	for (int i = 0; i < N; i++)
		g[i] = 1ll * g[i] * g[i] % mod;
	dft(g, -1);
}

int main()
{
	init();
	scanf("%d%d%d", &n, &k, &f);
	for (int i = 0; i <= k; i++)
		g[i] = 1;
	multi();
	for (int i = 1; i < n; i++)
	{
		int sum = 0;
		for (int j = 2 * k; j > k; j--)
		{
			(sum += g[j]) %= mod;
			g[j] = 0;
		}
		for (int j = k; j >= 0; j--)
		{
			(sum += g[j]) %= mod;
			g[j] = (1ll * (k - j) * g[j] + sum) % mod;
		}
		multi();
	}
	printf("%d\n", g[f]);
	return 0;
}