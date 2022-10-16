#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int N = 5e5 + 5;

int n, q;
char u[N], m[N], d[N];
pair<int, int> qr[N];
int qp[N], ans[N];

class FenwickTree
{
public:
	int v[N], s[N];
	void set(int p, int x)
	{
		int d = x - v[p];
		v[p] = x;
		for (int i = p; i < N; i += i & (-i))
			s[i] += d;
	}
	int get(int p)
	{
		int r = 0;
		for (int i = p; i; i -= i & (-i))
			r += s[i];
		return r;
	}
	int get(int l, int r)
	{
		return get(r) - get(l - 1);
	}
};

FenwickTree U, M, D;

set <int> Us, Ds;
int Um[N], Dm[N];

bool cmp(int a, int b)
{
	return qr[a].second < qr[b].second;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", u + 1);
	scanf("%s", m + 1);
	scanf("%s", d + 1);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		qr[i] = make_pair(x, y);
		qp[i] = i;
	}
	sort(qp + 1, qp + q + 1, cmp);
	for (int i = 1, j = 1; i <= n; i++)
	{
		if (u[i] == '1')
		{
			Um[i] = Um[i - 1];
			if (u[i - 1] == '1')
			{
				if (!Um[i - 1])
					U.set(i - 1, 0);
				Us.erase(i - 1);
			}
			if (m[i] == '1')
			{
				Um[i] = i;
				if (Um[i - 1])
					M.set(Um[i - 1], 0);
			}
			Us.insert(i);
			if (!Um[i])
				U.set(i, 1);
		}
		if (m[i] == '1')
		{
			if (m[i - 1] == '1')
				M.set(i - 1, 0);
			M.set(i, 1);
		}
		if (d[i] == '1')
		{
			Dm[i] = Dm[i - 1];
			if (d[i - 1] == '1')
			{
				if (!Dm[i - 1])
					D.set(i - 1, 0);
				Ds.erase(i - 1);
			}
			if (m[i] == '1')
			{
				Dm[i] = i;
				if (Dm[i - 1])
					M.set(Dm[i - 1], 0);
			}
			Ds.insert(i);
			if (!Dm[i])
				D.set(i, 1);
		}
		while (j <= q && qr[qp[j]].second == i)
		{
			int l = qr[qp[j]].first;
			ans[qp[j]] = U.get(l, i) + M.get(l, i) + D.get(l, i);
			set <int> :: iterator iU = Us.lower_bound(l);
			if (iU != Us.end())
				if (Um[*iU] > 0 && Um[*iU] < l)
					ans[qp[j]]++;
			set <int> :: iterator iD = Ds.lower_bound(l);
			if (iD != Ds.end())
				if (Dm[*iD] > 0 && Dm[*iD] < l)
					ans[qp[j]]++;
			j++;
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}