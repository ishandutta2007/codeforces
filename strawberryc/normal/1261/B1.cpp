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

const int N = 2e5 + 5;

int n, m, a[N], p[N], A[N], ans[N];

struct query
{
	int th, id;
};

std::vector<query> que[N];

inline bool comp(const int &x, const int &y)
{
	return a[x] > a[y] || (a[x] == a[y] && x < y);
}

void change(int x, int v)
{
	for (; x <= n; x += x & -x)
		A[x] += v;
}

int kth(int k)
{
	int res = 0, x = 0;
	for (int i = 19; i >= 0; i--)
		if (x + (1 << i) <= n && res + A[x + (1 << i)] < k)
			x += 1 << i, res += A[x];
	return x + 1;
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), p[i] = i;
	std::sort(p + 1, p + n + 1, comp);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(x); read(y);
		que[x].push_back((query) {y, i});
	}
	for (int i = 1; i <= n; i++)
	{
		change(p[i], 1);
		for (int j = 0; j < que[i].size(); j++)
			ans[que[i][j].id] = a[kth(que[i][j].th)];
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return puts(""), 0;
}