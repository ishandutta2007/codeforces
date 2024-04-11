#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 500005;

int n, p, q, r, a[MAXN], b[MAXN], c[MAXN], top;
vector < pa > v[MAXN];
set < pa > S;
LL ans, cur;

inline void solve(pa t)
{
	auto it = S.upper_bound(t), jt = it --;
	int last_x = t.xx;
	if (jt -> yy >= t.yy) return ;
	while (true)
	{
		cur += 1LL * (last_x - it -> xx) * (t.yy - jt -> yy);
		last_x = it -> xx;
		jt = it --;
		if (jt -> yy >= t.yy) break;
	}
	it = -- S.upper_bound(t);
	while (true)
	{
		if (it -> yy > t.yy) break;
		jt = it --;
		S.erase(jt);
	}
	S.insert(t);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = read(), p = read(), q = read(), r = read();
	ans = 1LL * p * q * r;
	for (int i = 1; i <= n; i ++) a[i] = read(), b[i] = read(), c[i] = read(), v[a[i]].pb(mp(b[i], r)), v[a[i]].pb(mp(q, c[i])), v[p].pb(mp(b[i], c[i]));
	S.insert(mp(0, r + 1)); S.insert(mp(q + 1, 0));
	for (int i = p; i; i --, ans -= cur) for (auto x : v[i]) solve(x);
	cout << ans << endl;
	return 0;
}