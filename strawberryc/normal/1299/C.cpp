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

typedef long long ll;

const int N = 1e6 + 5;

int n, a[N], top, lt[N];
ll sum[N];

struct point
{
	ll x, y; int id;
	
	friend inline point operator - (point a, point b)
	{
		return (point) {b.x - a.x, b.y - a.y};
	}
	
	friend inline ll operator * (point a, point b)
	{
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}
} stk[N];

int main()
{
	read(n); ll s = 0;
	for (int i = 1; i <= n; i++) read(a[i]);
	stk[top = 1] = (point) {0, 0, n + 1};
	for (int i = n; i >= 1; i--)
	{
		s += a[i];
		point x = (point) {n - i + 1, s, i};
		while (top > 1 && (stk[top - 1] - stk[top]) * (stk[top - 1] - x) >= 0)
			top--;
		stk[++top] = x; lt[i] = stk[top - 1].id;
	}
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i = lt[i])
	{
		int len = lt[i] - i; ll s = sum[lt[i] - 1] - sum[i - 1];
		for (int j = i; j < lt[i]; j++)
			printf("%.10lf\n", 1.0 * s / len);
	}
	return 0;
}