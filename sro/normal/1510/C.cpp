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

int n, m;
vector<int> nei[100005], son[100005];
int lgl[100005];
int ban[100005], fa[100005];
int dp[100005][2], frm[100005];

void dfs(int now, int lst) {
	fa[now] = lst; lgl[now] = 1;
	parse(to, nei[now]) {
		if (to == lst) continue;
		if (lgl[to]) {
			if (lgl[to] != 1) continue;
			for (int i = now; i != to; i = fa[i]) ban[i] = 1;
		} else {
			dfs(to, now);
			son[now].pub(to);
		}
	}
	lgl[now] = 2;
}

void dft(int now) {
	dp[now][0] = 0, dp[now][1] = Inf;
	int ups = 0;
	parse(to, son[now]) {
		dft(to); if (!ban[to]) ++ups;
		dp[now][1] = min(dp[now][0] + dp[to][1], dp[now][1] + dp[to][0]);
		dp[now][0] += dp[to][0];
	}
	int pip = dp[now][0] - (ups >> 1);
	if (ban[now]) {
		dp[now][0] = min(pip, dp[now][1] - ((ups - 1) >> 1));
		if (dp[now][0] != pip) frm[now] = 1;
		else frm[now] = 0;
		dp[now][1] = Inf;
	} else {
		int res = dp[now][0] - ((ups - 1) >> 1);
		dp[now][0] = min(res, dp[now][1] - ((ups - 2) >> 1));
		if (dp[now][0] != res) frm[now] = 1;
		else frm[now] = 0;
		dp[now][1] = pip;
	}
}

void dfu(int now, int tp) {
	if (tp) {
		parse(to, son[now]) dfu(to, 0);
		return;
	}
	int sel = -1;
	parse(to, son[now]) {
		if (ban[to] == 1) continue;
		if (frm[now] && (!~sel || dp[sel][1] - dp[sel][0] > dp[to][1] - dp[to][0])) sel = to;
	}
	parse(to, son[now]) {
		if (sel == to) ban[to] = 2;
		dfu(to, ban[to] == 2);
	}
}

int up[100005];
vector<pair<int, int> > ans;

void dfv(int now) {
	up[now] = -1;
	parse(to, son[now]) {
		dfv(to);
		if (~up[to]) {
			if (~up[now]) ans.pub(mak(up[now], up[to])), up[now] = -1;
			else up[now] = up[to];
		}
	}
	if (!~up[now] && !ban[now]) up[now] = now;
	if (~up[now] && ban[now]) {
		ans.pub(mak(up[now], fa[up[now]] == now ? fa[now] : now));
		up[now] = -1;
	}
}

void solve() {
	cont(i, n) nei[i].clear(), son[i].clear();
	cont(i, n) lgl[i] = 0, ban[i] = 0;
	cont(i, m) {
		int l; scanf("%d", &l);
		int lst = 0;
		while (l--) {
			int now; scanf("%d", &now);
			if (lst) nei[lst].pub(now), nei[now].pub(lst);
			lst = now;
		}
	}
	dfs(1, 0); ban[1] = 1; dft(1);
	dfu(1, 0); ans.clear(); dfv(1);
	// assert(SZ(ans) == dp[1][0]);
	printf("%d\n", SZ(ans));
	parse(it, ans) printf("%d %d\n", it.first, it.second);
}

int main() {
	while(scanf("%d%d", &n, &m) && n) solve();
	return 0;
}