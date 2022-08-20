#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

LL n, ret, f[105][2], g[105][2];

inline void Dp(int x, int p, int q, LL s)
{
	mset(f, 0);
	f[0][0] = 1;
	for (int i = 0; 1LL << i <= s; i ++)
	{
		mcpy(g, f), mset(f, 0);
		for (int j = 0; j <= (i < p); j ++)
			for (int k = 0; k <= (i < q); k ++)
			{
				int l = (s >> i & 1) ^ (j + k & 1);
				for (int m = 0; m + j + k <= x; m ++)
					f[m + j + k][j + k + l >> 1] += g[m][l];
			}
	}
	ret += f[x][0];
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i <= 50; i ++)
		for (int j = 0; j <= 50; j ++)
		{
			LL val = (1LL << i + 1) + (1LL << j + 1) - 3, cur;
			if (n < val)
				break;
			cur = n % val - (1LL << j) + 1;
			for (int k = 0; k <= i + j; k ++)
				if (cur + k >= 0 && !(cur + k & 1))
					Dp(k, max(i - 1, 0), max(j - 1, 0), cur + k >> 1);
		}
	cout << ret << endl;
}