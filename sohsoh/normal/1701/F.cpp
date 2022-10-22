#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const int MAXN = 2e5 + 10;

struct segment {
	ll sg_real[(MAXN + 100) << 2], sg_fake[(MAXN + 100) << 2], lz[(MAXN + 100) << 2], cnt[(MAXN + 100) << 2];
	bool F[(MAXN + 100) << 2];

	segment() {
		memset(sg_real, 0, sizeof sg_real);
		memset(sg_fake, 0, sizeof sg_fake);
		memset(lz, 0, sizeof lz);
		memset(cnt, 0, sizeof cnt);
	}

	inline void push(int v, int l, int r) {
		sg_real[v] += lz[v] * cnt[v];
		sg_fake[v] += lz[v] * (r - l + 1);
		if ((v << 1 | 1) < ((MAXN + 50) << 2)) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
		}

		lz[v] = 0;
	}

	void update(int ql, int qr, int val, int l, int r, int v) {
		push(v, l, r);
		if (ql > r || qr < l) return;
		if (ql <= l && qr >= r) {
			lz[v] += val;
			push(v, l, r);
			return;
		}

		int mid = (l + r) >> 1;
		update(ql, qr, val, l, mid, v << 1);
		update(ql, qr, val, mid + 1, r, v << 1 | 1);
		sg_real[v] = (sg_real[v << 1] + sg_real[v << 1 | 1]);
		sg_fake[v] = (sg_fake[v << 1] + sg_fake[v << 1 | 1]);
	}

	ll query(int ql, int qr, int l, int r, int v) {
		push(v, l, r);
		if (ql > r || qr < l) return 0;
		if (ql <= l && qr >= r) return sg_real[v];

		int mid = (l + r) >> 1;
		return query(ql, qr, l, mid, v << 1) + 
			query(ql, qr, mid + 1, r, v << 1 | 1);
	}

	inline void flip(int ind, int l = 1, int r = MAXN, int v = 1) {
		push(v, l, r);
		if (l == r) {
			cnt[v] = 1 - cnt[v];
			sg_real[v] = cnt[v] * sg_fake[v];
			return;
		}

		int mid = (l + r) >> 1;
		if (ind <= mid) flip(ind, l, mid, v << 1), push(v << 1 | 1, mid + 1, r);
		else flip(ind, mid + 1, r, v << 1 | 1), push(v << 1, l, mid);
	
		sg_real[v] = (sg_real[v << 1] + sg_real[v << 1 | 1]);
		sg_fake[v] = (sg_fake[v << 1] + sg_fake[v << 1 | 1]);
		cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
	}

	inline void update(int ql, int qr, int val) {
		ql = max(ql, 1);
		qr = min(qr, MAXN);
		if (ql > qr) return;

		update(ql, qr, val, 1, MAXN, 1);
	}

	inline ll query(int ql, int qr) {
		ql = max(ql, 1);
		qr = min(qr, MAXN);
		if (ql > qr) return 0;
		
		return query(ql, qr, 1, MAXN, 1);
	}
} sg1, sg2;
// sg1: cnt
// sg2: cnt i -> i + d

bool vis[MAXN];
int q, d;
ll ans;

inline ll C2(ll x) {
	return x * (x - 1) / 2;
}

inline ll ans_delta(int x) {
	return C2(sg1.query(x + 1, x + d)) + sg2.query(x - d, x - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> q >> d;
	for (int i = 1; i <= MAXN; i++)
		sg1.flip(i);

	while (q--) {
		int x;
		cin >> x;
		if (!vis[x]) {
			ans += ans_delta(x);
			sg2.flip(x);
			sg1.update(x, x, 1);
			sg2.update(x - d, x - 1, 1);
		} else {
			sg1.update(x, x, -1);	
			sg2.update(x - d, x - 1, -1);
			sg2.flip(x);
			ans -= ans_delta(x);
		}

		cout << ans << endl;
		vis[x] = !vis[x];
	}

	return 0;
}