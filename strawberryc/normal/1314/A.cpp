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

const int N = 2e5 + 5;

int n;
ll ans, sum;

std::priority_queue<int> pq;

struct elem
{
	int x, t;
} a[N];

inline bool comp(elem a, elem b)
{
	return a.x < b.x || (a.x == b.x && a.t > b.t);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i].x);
	for (int i = 1; i <= n; i++) read(a[i].t);
	std::sort(a + 1, a + n + 1, comp);
	int j = 1, nxt = 1, v = a[1].x;
	while (j <= n)
	{
		while (nxt <= n && a[nxt].x == v) sum += a[nxt].t, pq.push(a[nxt].t), nxt++;
		int tmp = pq.top();
		ans += sum - tmp; pq.pop(); sum -= tmp;
		if (pq.empty()) j = nxt, v = a[j].x;
		else j++, v++;
	}
	return std::cout << ans << std::endl, 0;
}