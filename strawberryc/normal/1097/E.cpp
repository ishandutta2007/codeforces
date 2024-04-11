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

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int C2[N], n, f[N], A[N], B[N], len[N], nxt[N], tot, tmp[N];
vi emp;
vvi ans;

struct elem
{
	int id, mx;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.mx < b.mx || (a.mx == b.mx && a.id < b.id);
	}
};

std::set<elem> orz;

void clean(int x)
{
	for (; x <= n; x += x & -x)
		A[x] = 0, B[x] = -1;
}

void change(int x, int i, int v)
{
	for (; x <= n; x += x & -x)
		if (v > A[x]) A[x] = v, B[x] = i;
}

int ask(int x)
{
	int id = -1, res = 0;
	for (; x; x -= x & -x)
		if (A[x] > res) res = A[x], id = B[x];
	return id;
}

vi lis(vi a)
{
	vi res;
	for (int i = 0; i < a.size(); i++)
	{
		if ((nxt[i] = ask(a[i])) == -1) len[i] = 1;
		else len[i] = len[nxt[i]] + 1;
		change(a[i], i, len[i]);
	}
	tot = 0; int mx = 1, id = 0;
	for (int i = 0; i < a.size(); i++)
		if (len[i] > mx) mx = len[i], id = i;
	for (int i = id; i != -1; i = nxt[i]) tmp[++tot] = i;
	for (int i = tot; i >= 1; i--) res.push_back(a[tmp[i]]);
	for (int i = 0; i < a.size(); i++) clean(a[i]);
	return res;
}

void construct(int len, vi a)
{
	int n = a.size(), m = ans.size(); orz.clear();
	for (int i = 0; i < len; i++) ans.push_back(emp);
	for (int i = 0; i < len; i++) orz.insert((elem) {m + i, INF});
	for (int i = 0; i < a.size(); i++)
	{
		std::set<elem>::iterator it = orz.lower_bound((elem) {-1, a[i]});
		elem x = *it; orz.erase(it);
		ans[x.id].push_back(a[i]);
		orz.insert((elem) {x.id, a[i]});
	}
}

void solve(vi a)
{
	if (a.empty()) return;
	int n = a.size(), it = 0; vi l = lis(a);
	if (l.size() > f[n])
	{
		ans.push_back(l); vi b;
		for (int i = 0; i < n; i++)
		{
			if (it < l.size() && a[i] == l[it]) {it++; continue;}
			b.push_back(a[i]);
		}
		return solve(b);
	}
	construct(l.size(), a);
}

void work()
{
	int x; vi a; read(n);
	for (int i = 0; i < n; i++) read(x), a.push_back(x);
	ans.clear(); solve(a);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i].size());
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d ", ans[i][j]);
		puts("");
	}
}

int main()
{
	memset(B, -1, sizeof(B));
	for (int i = 1; i <= 500; i++) C2[i] = i * (i + 1) >> 1;
	for (int i = 1; i < 500; i++)
		for (int j = C2[i]; j < C2[i + 1] && j <= 100000; j++)
			f[j] = i;
	int T; read(T);
	while (T--) work();
	return 0;
}