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
		res = (res << 3) + (res << 1) + (c - '0');
	return bo ? ~res + 1 : res;
}

typedef long long ll;

const int N = 2e5 + 5;

int n, m, k, tot, b[N];

ll ans;

struct node
{
	int id, val;
} a[N];

inline bool comp(node a, node b)
{
	return a.val > b.val;
}

int main()
{
	n = read(); m = read(); k = read();
	for (int i = 1; i <= n; i++) a[i].id = i, a[i].val = read();
	std::sort(a + 1, a + n + 1, comp);
	for (int i = 1; i <= k * m; i++) b[++tot] = a[i].id, ans += a[i].val;
	std::sort(b + 1, b + tot + 1);
	std::cout << ans << std::endl;
	for (int i = m; i < k * m; i += m)
		printf("%d ", b[i]);
	std::cout << std::endl;
	return 0;
}