#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

const int maxn = 1 << 20;

int N, M;

struct Segtree {
	int dt[maxn << 1], cv[maxn << 1], val[maxn << 1];
	void inline pu(int now) {
		dt[now] = val[now << 1] + val[now << 1 | 1];
		val[now] = cv[now] ? 0 : dt[now];
	}
	void inline init(int now = 1, int nl = 1, int nr = M - 1) {
		if (nl == nr) return dt[now] = 1, val[now] = 1, void();
		int m = (nl + nr) >> 1;
		init(now << 1, nl, m);
		init(now << 1 | 1, m + 1, nr);
		pu(now);
	}
	void inline add(int l, int r, int x, int now = 1, int nl = 1, int nr = M - 1) {
		if (nl > r || nr < l) return;
		if (nl >= l && nr <= r) {
			cv[now] += x;
			val[now] = cv[now] ? 0 : dt[now];
			return;
		}
		int m = (nl + nr) >> 1;
		add(l, r, x, now << 1, nl, m);
		add(l, r, x, now << 1 | 1, m + 1, nr);
		pu(now);
	}
} seg;

vector<pair<int, pair<int, int> > > s;

int main() {
	scanf("%d%d", &N, &M);
	rep(i, N) {
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		s.emplace_back(w, make_pair(l, r - 1));
	}
	seg.init();
	sort(s.begin(), s.end());
	int r = 0;
	int ans = 0x3f3f3f3f;
	rep(l, N) {
		while (r < N && seg.val[1]) {
			seg.add(s[r].second.first, s[r].second.second, 1);
			++r;
		}
		if (!seg.val[1]) ans = min(ans, s[r - 1].first - s[l].first);
		seg.add(s[l].second.first, s[l].second.second, -1);
	}
	printf("%d\n", ans);
	return 0;
}