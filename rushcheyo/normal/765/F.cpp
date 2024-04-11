#include <cstdio>
#include <vector>
#include <algorithm>

const int INF = 1000000000;
int n, m, a[100001], l[300001], r[300001], ans[300001];
std::vector<int> q[100001];

struct node
{
	std::vector<int> seq;
	int ans;
} T[262144];

void build(int u, int l, int r)
{
	T[u].ans = INF;
	if (l == r)
	{
		T[u].seq.push_back(a[l]);
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	T[u].seq = std::vector<int>(r - l + 1);
	std::merge(T[u << 1].seq.begin(), T[u << 1].seq.end(), T[u << 1 | 1].seq.begin(), T[u << 1 | 1].seq.end(), T[u].seq.begin());
	for (int i = 1; i <= r - l; i++)
		T[u].ans = std::min(T[u].ans, T[u].seq[i] - T[u].seq[i - 1]);
}
int query(int u, int l, int r, int ql, int qr)
{
	if (l >= ql && r <= qr) return T[u].ans;
	int mid = l + r >> 1;
	if (qr <= mid) return query(u << 1, l, mid, ql, qr);
	if (ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
	return std::min(query(u << 1, l, mid, ql, qr), query(u << 1 | 1, mid + 1, r, ql, qr));
}
void modify(int u, int l, int r, int qr, int v, int &d)
{
	if (l == r)
	{
		T[u].ans = std::min(T[u].ans, std::abs(v - a[l]));
		d = std::min(d, T[u].ans);
		return;
	}
	int mid = l + r >> 1;
	std::vector<int>::iterator it = lower_bound(T[u].seq.begin(), T[u].seq.end(), v);
	if ((it == T[u].seq.end() || *it >= v + d) && (it == T[u].seq.begin() || *(it - 1) <= v - d))
	{
		d = std::min(d, query(u, l, r, l, qr));
		return;
	}
	if (qr > mid)
		modify(u << 1 | 1, mid + 1, r, qr, v, d);
	modify(u << 1, l, mid, std::min(mid, qr), v, d);
	T[u].ans = std::min({T[u].ans, T[u << 1].ans, T[u << 1 | 1].ans});
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", l + i, r + i);
		q[r[i]].push_back(i);
	}
	for (int i = 2; i <= n; i++)
	{
		int d = INF;
		modify(1, 1, n, i - 1, a[i], d);
		for (int j : q[i])
			ans[j] = query(1, 1, n, l[j], r[j]);
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}