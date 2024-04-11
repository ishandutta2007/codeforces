#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

const int N = 30011;

int mod;
int a[N], b[N];
int fib[N];
// fib[i + k] = fib[i] * fib[k + 1] + fib[i - 1] * fib[k]
// v0 = v0[l] + fib[ls] * v1[r] + fib[ls - 1] * v0[r]
// v1 = v1[l] + fib[ls + 1] * v1[r] + fib[ls] * v0[r]

struct SegTree
{
	int l[N << 2], r[N << 2];
	int sz[N << 2];
	int v0[N << 2];
	int v1[N << 2];
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		sz[x] = v0[x] = v1[x] = 0;
		if(left + 1 != right)
		{
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	void change(int pos, int c, int x = 1)
	{
		if(l[x] + 1 == r[x])
		{
			sz[x] = c;
			v1[x] = (c ? b[pos] : 0);
		}
		else
		{
			int mid = (l[x] + r[x]) / 2;
			if(pos < mid)
				change(pos, c, 2 * x);
			else
				change(pos, c, 2 * x + 1);
			sz[x] = sz[2 * x] + sz[2 * x + 1];
			if(sz[2 * x])
			{
				v0[x] = v0[2 * x] + fib[sz[2 * x]] * v1[2 * x + 1] +
					fib[sz[2 * x] - 1] * v0[2 * x + 1];
				v1[x] = v1[2 * x] + fib[sz[2 * x] + 1] * v1[2 * x + 1] +
					fib[sz[2 * x]] * v0[2 * x + 1];
			}
			else
			{
				v0[x] = v0[2 * x + 1];
				v1[x] = v1[2 * x + 1];
			}
			v0[x] %= mod;
			v1[x] %= mod;
		}
	}
	int query()
	{
		return v1[1];
	}
}st;

int Sqrt = 160;
struct Query
{
	int l, r;
	int id;
	Query() { }
	Query(int l, int r, int id) : l(l), r(r), id(id) { }
	bool operator <(const Query &rhs) const
	{
		if(l / Sqrt == rhs.l / Sqrt)
		{
			if(l / Sqrt % 2)
				return r < rhs.r;
			return r > rhs.r;
		}
		return l < rhs.l;
	}
}query[N];

int ans[N];
map <int, int> disc;
map <int, int> all;
void add(int pos)
{
	all[a[pos]] ++;
	if(all[a[pos]] == 1)
		st.change(disc[a[pos]], 1);
}
void del(int pos)
{
	all[a[pos]] --;
	if(all[a[pos]] == 0)
		st.change(disc[a[pos]], 0);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	//cin >> n >> mod;
	scanf("%d%d", &n, &mod);
	Sqrt = (int)sqrt(n);
	fib[1] = fib[2] = 1;
	for(int i = 3; i < N; i ++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	for(int i = 1; i <= n; i ++)
	{
		//cin >> a[i];
		scanf("%d", a + i);
		disc[a[i]] = 0;
	}

	int cnt = 0;
	for(auto it = disc.begin(); it != disc.end(); it ++)
	{
		b[cnt] = (it -> first) % mod;
		it -> second = cnt ++;
	}
	st.init(0, cnt);

	int m;
	//cin >> m;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++)
	{
		//cin >> query[i].l >> query[i].r;
		scanf("%d%d", &query[i].l, &query[i].r);
		query[i].id = i;
	}
	sort(query, query + m);

	int l = 1, r = 0;
	for(int i = 0; i < m; i ++)
	{
		Query &q = query[i];
		while(l > q.l)
			add(-- l);
		while(r < q.r)
			add(++ r);
		while(l < q.l)
			del(l ++);
		while(r > q.r)
			del(r --);

		ans[q.id] = st.query();
	}
	for(int i = 0; i < m; i ++)
		//cout << ans[i] << '\n';
		printf("%d\n", ans[i]);
	return 0;
	
	/*
	mod = 233;
	fib[1] = fib[2] = 1;
	fib[3] = 2;
	fib[4] = 3;
	fib[5] = 5;
	st.init(0, 5);
	iota(b, b + 5, 0);
	for(int i = 0; i < 5; i ++)
	{
		st.change(i, 1);
		cout << st.query() << '\n';
	}
	for(int i = 0; i < 5; i ++)
	{
		st.change(i, 0);
		cout << st.query() << '\n';
	}
	*/
}