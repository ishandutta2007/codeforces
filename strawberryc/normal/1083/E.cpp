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

typedef long long ll;

inline ll readll()
{
	ll res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e6 + 5;

int n, H, T, Q[N];
ll f[N], ans;

struct point
{
	int x, y; ll a;
} p[N];

inline bool comp(const point &a, const point &b)
{
	return a.x < b.x;
}

bool check(int i, int j, int k)
{
	return 1.0 * (f[j] - f[i]) / (p[j].x - p[i].x) <=
		1.0 * (f[k] - f[j]) / (p[k].x - p[j].x);
}

ll calc(int j, int i)
{
	return f[j] - 1ll * p[j].x * p[i].y;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		p[i].x = read(), p[i].y = read(), p[i].a = readll();
	std::sort(p + 1, p + n + 1, comp);
	H = T = 1;
	for (int i = 1; i <= n; i++)
	{
		while (H < T && calc(Q[H], i) <= calc(Q[H + 1], i)) H++;
		f[i] = calc(Q[H], i) + 1ll * p[i].x * p[i].y - p[i].a;
		while (H < T && check(Q[T - 1], Q[T], i)) T--;
		Q[++T] = i;
		ans = Max(ans, f[i]);
	}
	std::cout << ans << std::endl;
	return 0;
}