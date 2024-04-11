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

const int MAXN = 50005;

int n, s, x, val[MAXN], nxt[MAXN], p[MAXN], cv = -1, cp;

inline int Query(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	val[x] = Read(), nxt[x] = Read();
}

inline void Print(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

int main()
{
#ifdef wxh010910
	//freopen("data.in", "r", stdin);
#endif
	srand(time(0));
	n = Read(), s = Read(), x = Read();
	for (int i = 1; i <= n; i ++)
		p[i] = i;
	random_shuffle(p + 1, p + n + 1);
	for (int i = 1; i <= n; i ++)
		if (p[i] == s)
			swap(p[i], p[1]);
	for (int i = 1; i <= min(n, 1000); i ++)
	{
		Query(p[i]);
		if (val[p[i]] < x && val[p[i]] > cv)
			cv = val[p[i]], cp = p[i];
	}
	if (!cp)
		Print(val[s]);
	while (true)
	{
		if (!~nxt[cp])
			Print(-1);
		cp = nxt[cp];
		Query(cp);
		if (val[cp] >= x)
			Print(val[cp]);
	}
	return 0;
}