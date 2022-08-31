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

int n, m, nxt[26], use[26], pre[26];
vector <int> ans;
char s[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 0; i < 26; i ++)
		nxt[i] = -1;
	for (int i = 1, l; i <= n; i ++)
	{
		scanf("%s", s + 1), l = strlen(s + 1);
		for (int j = 1; j <= l; j ++)
			use[s[j] - 'a'] = 1;
		for (int j = 1; j < l; j ++)
		{
			if (~nxt[s[j] - 'a'] && nxt[s[j] - 'a'] != s[j + 1] - 'a')
				return puts("NO");
			nxt[s[j] - 'a'] = s[j + 1] - 'a', pre[s[j + 1] - 'a'] = 1;
		}
	}
	for (int i = 0; i < 26; i ++)
		m += use[i];
	for (int i = 0; i < 26; i ++)
		if (use[i] && !pre[i])
			for (int j = i; ~j; j = nxt[j])
			{
				ans.pb(j);
				if (ans.size() > m)
					return puts("NO"), 0;
			}
	if (ans.size() < m)
		return puts("NO"), 0;
	for (auto c : ans)
		putchar(c + 'a');
	return putchar(10), 0;
}