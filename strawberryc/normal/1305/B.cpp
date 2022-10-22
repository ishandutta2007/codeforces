#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 1005;

int n, top, stk[N], m, a[N], b[N];
char s[N];
bool is;

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (s[i] == '(' && s[j] == ')')
				is = 1;
	if (!is) return puts("0"), 0;
	puts("1");
	for (int i = 1, j = n; i < j; i++, j--)
	{
		while (i <= n && s[i] == ')') i++;
		while (j >= 1 && s[j] == '(') j--;
		if (i < j) a[++m] = i, b[m] = j;
	}
	std::cout << (m << 1) << std::endl;
	for (int i = 1; i <= m; i++) printf("%d ", a[i]);
	for (int i = m; i >= 1; i--) printf("%d ", b[i]);
	return puts(""), 0;
}