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

vector <int> ans;
int n;

inline int F(int x)
{
	int ret = x;
	while (x)
		ret += x % 10, x /= 10;
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = max(1, n - 100); i <= n; i ++)
		if (F(i) == n)
			ans.pb(i);
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d\n", x);
	return 0;
}