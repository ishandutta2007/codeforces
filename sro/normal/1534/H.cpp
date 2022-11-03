#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 100005;
int n;
vector<int> nei[maxn];
vector<pair<int, int> > sis[maxn], nis[maxn];
int dp[maxn], f[maxn], mlf[maxn];
int pre[maxn], suf[maxn];

void dfs1(int now, int lst) {
	sis[now].clear();
	parse(to, nei[now]) if (to != lst) {
		dfs1(to, now);
		sis[now].emb(dp[to], to);
	}
	if (!SZ(sis[now])) return (void)(dp[now] = 1, mlf[now] = now);
	sort(all(sis[now])); reverse(all(sis[now]));
	int res = -1;
	loop(i, SZ(sis[now])) {
		if (i + sis[now][i].first > res) {
			res = i + sis[now][i].first;
			mlf[now] = mlf[sis[now][i].second];
		}
	}
	dp[now] = res;
}

void dfs2(int now, int lst) {
	nis[now] = sis[now];
	if (now != 1 && !f[now]) f[now] = 1;
	if (now != 1) nis[now].emb(f[now], lst);
	sort(all(nis[now])); reverse(all(nis[now]));
	int sz = SZ(nis[now]);
	memset(pre, 0, sizeof(int) * (sz + 1));
	memset(suf, 0, sizeof(int) * (sz + 1));
	loop(i, sz) pre[i] = max(i ? pre[i - 1] : 0, nis[now][i].first + i);
	range(i, sz - 1, 0, -1) suf[i] = max(suf[i + 1], nis[now][i].first + i);
	loop(i, sz) if (nis[now][i].second != lst) f[nis[now][i].second] = max(i ? pre[i - 1] : 0, suf[i + 1] - 1);
	parse(to, nei[now]) if (to != lst) dfs2(to, now);
}

int mem[maxn];	

int query(int x) {
	if (mem[x]) return mem[x];
	printf("? %d\n", x); fflush(stdout);
	scanf("%d", mem + x); return mem[x];
}

int solve(int now) {
	loop(i, SZ(sis[now])) if (query(mlf[sis[now][i].second]) != now) return solve(sis[now][i].second);
	return now;
}

int main() {
	scanf("%d", &n);
	cont(i, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		nei[u].pub(v); nei[v].pub(u);
	}
	dfs1(1, 0); dfs2(1, 0);
	int ans = 0;
	cont(i, n) if (SZ(nis[i])) {
		int sz = SZ(nis[i]), mx = 0;
		cont(j, sz - 1) mx = max(mx, nis[i][j].first + j - 1);
		mx += nis[i][0].first;
		ans = max(ans, mx);
	}
	printf("%d\n", ans); fflush(stdout);
	// dp  dp 
	int F; scanf("%d", &F);
	dfs1(F, 0);
	int x = 0, y = 0;
	loop(i, SZ(sis[F])) {
		int res = query(mlf[sis[F][i].second]);
		if (res != F) y = x, x = sis[F][i].second;
		if (y) break;
	}
	x = x ? solve(x) : F;
	y = y ? solve(y) : F;
	printf("! %d %d\n", x, y); fflush(stdout);
	return 0;
}