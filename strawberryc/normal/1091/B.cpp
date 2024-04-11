#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1005, M = 1e6 + 5;

int n, m, x[N], y[N], a[N], b[N];

struct node
{
	int x, y;
} point[M];

inline bool comp(node a, node b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read();
	if (n == 1) return std::cout << x[1] + a[1] << " "
		<< y[1] + b[1] << std::endl, 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			point[++m] = (node) {x[i] + a[j], y[i] + b[j]};
	std::sort(point + 1, point + m + 1, comp);
	int tot = 0;
	for (int i = 1; i <= m; i++)
		if (i == 1 || point[i].x != point[i - 1].x
			|| point[i].y != point[i - 1].y)
				tot = 1;
		else if ((++tot) == n) return printf("%d %d\n", point[i].x, point[i].y), 0;
	return 0;
}