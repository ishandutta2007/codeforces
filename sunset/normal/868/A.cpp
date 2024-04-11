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

int n;
char s[105][3];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s", s[0]);
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", s[i]);
		if (s[i][0] == s[0][0] && s[i][1] == s[0][1])
			return puts("YES"), 0;
	}
	for (int i = 1; i <= n; i ++)
		if (s[i][1] == s[0][0])
			for (int j = 1; j <= n; j ++)
				if (s[j][0] == s[0][1])
					return puts("YES"), 0;
	return puts("NO"), 0;
}