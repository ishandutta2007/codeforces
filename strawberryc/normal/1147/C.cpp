#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 55, INF = 0x3f3f3f3f;

int n, a[N], mx = INF, cnt;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		if ((a[i] = read()) < mx) mx = a[i];
	for (int i = 1; i <= n; i++)
		if (a[i] == mx) cnt++;
	puts(cnt <= (n >> 1) ? "Alice" : "Bob");
	return 0;
}