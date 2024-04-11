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

const int MAXN = 100005;

vector <int> ans;
int n, v[MAXN];

inline void Dfs(int x)
{
	v[x] = 1;
	if (!v[x + n >> 1])
		Dfs(x + n >> 1);
	if (!v[x >> 1])
		Dfs(x >> 1);
	ans.pb(x);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	if (n & 1)
		return puts("-1"), 0;
	Dfs(0);
	printf("0");
	for (int i = 0; i < n; i ++)
		printf(" %d", ans[i]);
	putchar(10);
	return 0;
}