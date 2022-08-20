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

int n, m, cnt[16];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
	{
		int x = 0;
		for (int j = 1; j <= m; j ++)
			x = x << 1 | Read();
		cnt[x] ++;
	}
	for (int i = 0; i < (1 << m); i ++)
		for (int j = 0; j < (1 << m); j ++)
			if (!(i & j))
				if (cnt[i] && cnt[j])
					return puts("YES"), 0;
	return puts("NO"), 0;
}