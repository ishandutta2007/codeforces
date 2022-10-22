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

const int N = 14005;

int n, tot;

int main()
{
	int x;
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		if (abs(x) % 2 == 0) {printf("%d\n", x / 2); continue;}
		tot++;
		if (x > 0)
		{
			if (tot & 1) printf("%d\n", x / 2);
			else printf("%d\n", x / 2 + 1);
		}
		else
		{
			if (tot & 1) printf("%d\n", -(abs(x) / 2) - 1);
			else printf("%d\n", -(abs(x) / 2));
		}
	}
	return 0;
}