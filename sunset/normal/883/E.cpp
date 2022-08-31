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

int n, m, ans, use[26];
char s[MAXN][55], t[55];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), scanf("%s", t + 1);
	for (int i = 1; i <= n; i ++)
		if (t[i] != '*')
			use[t[i] - 'a'] = 1;
	m = Read();
	for (int i = 1; i <= m; i ++)
	{
		scanf("%s", s[i] + 1);
		bool flg = true;
		for (int j = 1; j <= n && flg; j ++)
		{
			if (t[j] != '*' && s[i][j] != t[j])
				flg = false;
			if (t[j] == '*' && use[s[i][j] - 'a'])
				flg = false;
		}
		if (!flg)
			i --, m --;
	}
	for (int i = 0; i < 26; i ++)
		if (!use[i])
		{
			bool ok = true;
			for (int j = 1; j <= m && ok; j ++)
			{
				bool flg = false;
				for (int k = 1; k <= n && !flg; k ++)
					if (s[j][k] == i + 'a')
						flg = true;
				if (!flg)
					ok = false;
			}
			ans += ok;
		}
	return printf("%d\n", ans), 0;
}