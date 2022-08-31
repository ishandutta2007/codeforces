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

const int MAXN = 5005;

int n, m, a[MAXN], b[MAXN], cnt[MAXN], c[MAXN][MAXN];
vector <int> ans;

inline int Query(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	return Read();
}

int main()
{
#ifdef wxh010910
#endif
	n = Read();
	for (int i = 0; i < n; i ++)
		c[0][i] = Query(0, i);
	for (int i = 1; i < n; i ++)
		c[i][0] = Query(i, 0);
	for (int i = 1; i < n; i ++)
		for (int j = 1; j < n; j ++)
			c[i][j] = c[0][j] ^ c[i][0] ^ c[0][0];
	for (int x = 0; x < n; x ++)
	{
		bool flg = true;
		for (int i = 0; i < n; i ++)
			cnt[i] = 0;
		for (int i = 0; i < n && flg; i ++)
		{
			b[i] = x ^ c[0][i];
			if (b[i] >= n || cnt[b[i]])
				flg = false;
			else
				cnt[b[i]] ++;
		}
		if (!flg)
			continue;
		for (int i = 0; i < n; i ++)
			a[b[i]] = i;
		if (a[0] ^ x)
			continue;
		for (int i = 0; i < n && flg; i ++)
			if (a[i] ^ b[0] ^ c[i][0])
				flg = false;
		if (flg)
			if (!m ++)
				for (int i = 0; i < n; i ++)
					ans.pb(a[i]);
	}
	printf("!\n%d\n", m);
	for (int i = 0; i < n; i ++)
		printf("%d ", ans[i]);
	putchar(10);
	fflush(stdout);
	return 0;
}