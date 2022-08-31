#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

vector < vector < int > > v;

inline void add(int x, int y, int z)
{
	v.pb({3, x, y, z});
}

inline void add(int x, int y, int z, int w)
{
	v.pb({4, x, y, z, w});
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	int n = read();
	if (n & 1)
	{
		add(1, 2, 3);
		add(1, 2, 3);
		for (int i = 3; i < n; add(i, i + 1, i + 2), add(i, i + 1, i + 2), i += 2)
			for (int j = 1; j < i; j += 2)
				add(j, i + 1, j + 1, i + 2), add(j, i + 1, j + 1, i + 2);
	}
	else
	{
		add(1, 2, 3, 4);
		add(1, 2, 4, 3);
		add(1, 4, 2, 3);
		for (int i = 4; i < n; add(i - 1, i + 1, i, i + 2), add(i - 1, i + 1, i + 2), add(i, i + 1, i + 2), i += 2)
			for (int j = 1; j < i - 2; j += 2)
				add(j, i + 1, j + 1, i + 2), add(j, i + 1, j + 1, i + 2);
	}
	printf("%d\n", v.size());
	for (auto c : v)
	{
		for (auto x : c)
			printf("%d ", x);
		putchar(10);
	}
}