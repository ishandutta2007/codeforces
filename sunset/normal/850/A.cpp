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

const int MAXN = 1005;

int n, a[5][MAXN];
vector <int> ans;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	if (n > 11)
		return puts("0"), 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < 5; j ++)
			a[j][i] = Read();
	for (int i = 1; i <= n; i ++)
	{
		bool flag = true;
		for (int j = 1; j <= n; j ++)
			if (i ^ j)
				for (int k = j + 1; k <= n; k ++)
					if (i ^ k)
					{
						int s = 0;
						for (int l = 0; l < 5; l ++)
							s += (a[l][j] - a[l][i]) * (a[l][k] - a[l][i]);
						if (s > 0)
							flag = false;
					}
		if (flag)
			ans.pb(i);
	}
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d\n", x);
	return 0;	
}