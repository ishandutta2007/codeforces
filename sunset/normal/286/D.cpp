#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 300005;

int n, m, c, k[MAXN], b[MAXN], l[MAXN], r[MAXN], t[MAXN], q[MAXN], L[MAXN];
vector <int> add[MAXN], del[MAXN];
multiset <int> s;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	m = Read(), n = Read();
	for (int i = 1; i <= n; i ++)
		L[++ c] = l[i] = Read(), L[++ c] = r[i] = Read(), t[i] = Read();
	for (int i = 1; i <= m; i ++)
		L[++ c] = q[i] = Read();
	sort(L + 1, L + c + 1), c = unique(L + 1, L + c + 1) - L - 1;
	for (int i = 1; i <= n; i ++)
		l[i] = lower_bound(L + 1, L + c + 1, l[i]) - L, r[i] = lower_bound(L + 1, L + c + 1, r[i]) - L, add[l[i]].pb(t[i]), del[r[i]].pb(t[i]);
	for (int i = 1; i <= m; i ++)
		q[i] = lower_bound(L + 1, L + c + 1, q[i]) - L;
	for (int i = 1; i < c; i ++)
	{
		for (auto x : add[i])
			s.insert(x);
		for (auto x : del[i])
			s.erase(s.find(x));
		if (s.empty())
			continue;
		int tim = *s.begin(), l = L[i], r = L[i + 1], pos_s = lower_bound(L + 1, L + c + 1, tim - r) - L, pos_t = lower_bound(L + 1, L + c + 1, tim - l) - L;
		b[pos_s] += r - tim, b[pos_t] += tim - l, k[pos_s] ++, k[pos_t] --;
	}
	for (int i = 1; i <= c; i ++)
		k[i] += k[i - 1], b[i] += b[i - 1];
	for (int i = 1; i <= m; i ++)
		printf("%d\n", k[q[i]] * L[q[i]] + b[q[i]]);
	return 0;
}