#include <bits/stdc++.h>

// 0830
//

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 4e5 + 5;

int n, c1, c2, m;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		if (read() == 1) c1++;
		else c2++;
	if (!c2)
	{
		for (int i = 1; i <= n; i++) printf("1 ");
		return puts(""), 0;
	}
	if (!c1)
	{
		for (int i = 1; i <= n; i++) printf("2 ");
		return puts(""), 0;
	}
	c1--; c2--; printf("2 1 ");
	m = c1 + c2 * 2;
	if (m & 1) c1--;
	while (c1--) printf("1 ");
	while (c2--) printf("2 ");
	if (m & 1) printf("1 ");
	puts("");
	return 0;
}