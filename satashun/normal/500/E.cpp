#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int SZ = 1 << 18;

struct segtree_max {
	vector<int> dat;

	void init() {
		dat.resize(SZ * 2);
		rep(i, SZ * 2) dat[i] = INT_MIN;
	}

	void update(int pos, int x) {
		pos += SZ - 1;
		dat[pos] = x;

		while (pos > 0) {
			pos = (pos - 1) / 2;
			dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
		}
	}

	int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
		if (b <= l || r <= a) return INT_MIN;
		if (a <= l && r <= b) return dat[k];
		return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
	}
} seg;

int n, q;
int p[200010];
int l[200010];
int r[19][200010];
int cost[19][200010];

int main() {
	seg.init();

	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &p[i], &l[i]);

	for (int i = n-1; i >= 0; --i) {
		int up = upper_bound(p, p + n, p[i] + l[i]) - p;

		int u = max(seg.get(i, up), p[i]+l[i]);
		//cout<<u<<endl;
		seg.update(i, u);

		int to = upper_bound(p, p + n, u) - p;

		r[0][i] = to;
		//cout<<i<<" "<<to<<endl;
		cost[0][i] = (to == n ? 0 : p[to] - u);
	}

	r[0][n] = n;
	cost[0][n] = 0;

	rep(i, 18) {
		for (int j = 0; j <= n; ++j) {
			r[i+1][j] = r[i][r[i][j]];
			cost[i+1][j] = cost[i][j] + cost[i][r[i][j]];
		}
	}

	scanf("%d", &q);

	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;

		int ret = 0;

		for (int i = 18; i >= 0; --i) {
			if (r[i][a] <= b) {
				ret += cost[i][a];
				a = r[i][a];
			}
		}

		if (r[0][a] <= b) {
			ret += cost[0][a];
		}

		printf("%d\n", ret);
	}

	return 0;
}