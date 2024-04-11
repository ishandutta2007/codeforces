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

const int MAXN = 2000005;

int n, m;
char s[MAXN], t[MAXN];
set < int > S;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int i = 1; i <= 2000001; i ++)
		S.insert(i);
	n = Read();
	while (n --)
	{
		scanf("%s", t + 1);
		int l = strlen(t + 1), k = Read();
		while (k --)
		{
			int x = Read();
			m = max(m, x + l - 1);
			while (true)
			{
				auto it = S.lower_bound(x);
				if (*it >= x + l)
					break;
				s[*it] = t[*it - x + 1];
				S.erase(it);
			}
		}
	}
	for (int i = 1; i <= m; i ++)
		if (s[i])
			putchar(s[i]);
		else
			putchar('a');
	putchar(10);
	return 0;
}