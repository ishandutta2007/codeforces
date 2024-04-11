#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

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

const int MAXN = 100005;

int bit[4][10][10][MAXN], a[MAXN], n, Q;
char s[MAXN];

inline int Lowbit(int x) { return x & -x; }
inline void Modify(int *bit, int x, int v) { for (; x <= n; x += Lowbit(x)) bit[x] += v; }
inline int Query(int *bit, int x) { int ret = 0; for (; x; x -= Lowbit(x)) ret += bit[x]; return ret; }

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s", s + 1); n = strlen(s + 1);

	for (int i = 1; i <= n; i ++)
	{
		a[i] = s[i] == 'A' ? 0 : s[i] == 'G' ? 1 : s[i] == 'C' ? 2 : 3;
		for (int j = 1; j <= 10; j ++)
			Modify(bit[a[i]][j - 1][i % j], i, 1);
	}

	for (Q = Read(); Q; Q --)
		if (Read() == 1)
		{
			int x = Read(); scanf("%s", s + 1);
			for (int i = 1; i <= 10; i ++)
				Modify(bit[a[x]][i - 1][x % i], x, -1);
			a[x] = s[1] == 'A' ? 0 : s[1] == 'G' ? 1 : s[1] == 'C' ? 2 : 3;
			for (int i = 1; i <= 10; i ++)
				Modify(bit[a[x]][i - 1][x % i], x, 1);
		}
		else
		{
			int l = Read(), r = Read(); scanf("%s", s);
			int len = strlen(s), ret = 0;
			for (int i = 0; i < len; i ++)
				ret += Query(bit[s[i] == 'A' ? 0 : s[i] == 'G' ? 1 : s[i] == 'C' ? 2 : 3][len - 1][(l + i) % len], r) - Query(bit[s[i] == 'A' ? 0 : s[i] == 'G' ? 1 : s[i] == 'C' ? 2 : 3][len - 1][(l + i) % len], l - 1);
			printf("%d\n", ret);
		}
	return 0;
}