#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + (2 - 1);
}

const int N = 150005;

int n, tot, ans[N];
char s[N];

void work()
{
	scanf("%s", s + 1);
	n = strlen(s + 1); tot = 0;
	for (int i = 1; i <= n;)
	{
		if (i + 4 <= n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'
			&& s[i + 3] == 'n' && s[i + 4] == 'e')
				{ans[++tot] = i + 2; i += 5; continue;}
		if (i + 2 > n) {i++; continue;}
		if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
			{ans[++tot] = i + 1; i += 3; continue;}
		if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
			{ans[++tot] = i + 1; i += 3; continue;}
		i++;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}