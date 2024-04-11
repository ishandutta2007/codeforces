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

const int N = 1e6 + 5, M = N * 6;

int n, w, l, m, mx[N];
ll ans;

struct modify
{
	int tim, num, cl; bool is;
} que[M];

std::multiset<int> pq[N];

inline bool comp(modify a, modify b)
{
	return a.tim < b.tim || (a.tim == b.tim && a.is > b.is);
}

void ins(int row, int num)
{
	ans -= mx[row];
	pq[row].insert(num);
	ans += (mx[row] = *--pq[row].end());
}

void del(int row, int num)
{
	ans -= mx[row];
	pq[row].erase(pq[row].find(num));
	ans += (mx[row] = *--pq[row].end());
}

int main()
{
	int x;
	read(n); read(w);
	for (int i = 1; i <= n; i++)
	{
		read(l);
		for (int j = 1; j <= l; j++)
		{
			read(x);
			que[++m] = (modify) {j, x, i, 1};
			que[++m] = (modify) {j + w - l + 1, x, i, 0};
		}
		que[++m] = (modify) {1, 0, i, 1};
		que[++m] = (modify) {w + 1, 0, i, 0};
		que[++m] = (modify) {w - l + 1, 0, i, 0};
		que[++m] = (modify) {l + 1, 0, i, 1};
	}
	std::sort(que + 1, que + m + 1, comp);
	x = 1;
	for (int i = 1; i <= w; i++)
	{
		while (x <= m && que[x].tim <= i)
		{
			if (que[x].is) ins(que[x].cl, que[x].num);
			else del(que[x].cl, que[x].num);
			x++;
		}
		printf("%lld ", ans);
	}
	return puts(""), 0;
}