#include<bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<LL, LL>;
#define endl '\n'
const LL N = 400005;
LL x[N], p[N];

struct SegTree {
	LL n;
	LL v[N * 4], d[N * 4];
	LL cnt[N * 4];
	
	inline void add(LL u, LL dd) {
		v[u] += dd, d[u] += dd;
//		v[u] += dd * cnt[u], d[u] += dd;
//		v[u] = dd * cnt[u], d[u] = dd;
//		v[u] = cnt[u], d[u] = dd;
	}
	
	inline void down(LL u) {
		LL& dd = d[u];
		if (!dd) return;
		add(u * 2, dd);
		add(u * 2 + 1, dd);
		dd = 0;
	}
	
	inline void up(LL u) {
//		v[u] = min(v[u * 2], v[u * 2 + 1]);
		v[u] = max(v[u * 2], v[u * 2 + 1]);
//		v[u] = v[u * 2] + v[u * 2 + 1];
	}
	
	void build(LL u, LL st, LL en) {
		d[u] = 0;
		if (st == en) {
			v[u] = 0;
			return;
		}
		LL md = (st + en) / 2;
		build(u * 2, st, md);
		build(u * 2 + 1, md + 1, en);
		cnt[u] = cnt[u * 2] + cnt[u * 2 + 1];
		up(u);
	}
	
	inline void update(LL u, LL st, LL en, LL l, LL r, LL dd) {
		if (l <= st && en <= r) {
			add(u, dd);
			return;
		}
		LL md = (st + en) / 2;
		down(u);
		if (l <= md) update(u * 2, st, md, l, r, dd);
		if (r > md) update(u * 2 + 1, md + 1, en, l, r, dd);
		up(u);
	}
	
	inline LL get(LL u, LL st, LL en, LL l, LL r) {
		if (l <= st && en <= r) return v[u];
		LL md = (st + en) / 2;
		down(u);
		
//		LL rlt = INF;
//		if (l <= md) chkmin(rlt, get(u * 2, st, md, l, r));
//		if (r > md) chkmin(rlt, get(u * 2 + 1, md + 1, en, l, r));
		
		LL rlt = -LLONG_MAX;
		if (l <= md) chkmax(rlt, get(u * 2, st, md, l, r));
		if (r > md) chkmax(rlt, get(u * 2 + 1, md + 1, en, l, r));

//		LL rlt = 0;
//		if (l <= md) rlt += get(u * 2, st, md, l, r);
//		if (r > md) rlt += get(u * 2 + 1, md + 1, en, l, r);

		up(u);
		return rlt;
	}
	
	inline void update(LL l, LL r, LL val) {
		if (l > r) return;
		update(1, 0, n, l, r, val);
	}
	
	inline LL get(LL l, LL r) {
		if (l > r) return 0;
		return get(1, 0, n, l, r);
	}
	//Add-min Tree
	
	void build(LL m) {
		n = m;
		build(1, 0, n);
	}
}H, NUM, ST[3];

LL h[N];
LL pos[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	LL T; cin >> T;
	
	while (T --) {
		LL n, m; cin >> n >> m;
		vector<LL> v;
		for (LL i = 0; i < n; i ++) {
			cin >> x[i] >> p[i];
			v.push_back(x[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		LL vn = v.size();
		H.build(vn + 5);
		NUM.build(vn + 5);
		for (LL i = 0; i < 3; i ++) ST[i].build(vn + 5);
		for (LL i = 0; i < n; i ++) {
			pos[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
		}
		for (LL i = 0; i < n; i ++) {
			LL k = lower_bound(v.begin(), v.end(), x[i] - p[i]) - v.begin();
			H.update(k, pos[i] - 1, p[i] - x[i]);
			NUM.update(k, pos[i] - 1, 1);
			k = upper_bound(v.begin(), v.end(), x[i] + p[i]) - v.begin() - 1;
			H.update(pos[i] + 1, k, p[i] + x[i]);
			NUM.update(pos[i] + 1, k, -1);
			H.update(pos[i], pos[i], p[i]);
		}
		for (LL i = 0; i < vn; i ++) {
			h[i] = H.get(i, i) + NUM.get(i, i) * v[i];
		}
		for (LL i = 0; i < vn; i ++) {
			for (LL j = 0; j < 3; j ++) ST[j].update(i, i, h[i]);
		}
		for (LL i = 0; i < vn; i ++) {
			ST[0].update(i, i, v[i]);
			ST[1].update(i, i, -v[i]);
		}
		for (LL i = 0; i < n; i ++) {
			LL l = lower_bound(v.begin(), v.end(), x[i] - p[i]) - v.begin();
			LL r = upper_bound(v.begin(), v.end(), x[i] + p[i]) - v.begin() - 1;
//			cerr << pos[i] << ' ' << l << ' ' << r << endl;
			LL val = max(ST[2].get(0, l - 1), ST[2].get(r + 1, vn - 1));
//			cerr << val << endl;
			ST[0].update(pos[i] + 1, r, -p[i] - x[i]);
			ST[1].update(l, pos[i] - 1, x[i] - p[i]);
			chkmax(val, ST[2].get(pos[i], pos[i]) - p[i]);
//			cerr << val << endl;
			chkmax(val, ST[0].get(pos[i] + 1, r));
			chkmax(val, ST[1].get(l, pos[i] - 1));
			ST[0].update(pos[i] + 1, r, p[i] + x[i]);
			ST[1].update(l, pos[i] - 1, p[i] - x[i]);
//			cerr << val << endl;
			if (val > m) cout << 0;
			else cout << 1;
		}
		cout << endl;
	}
	return 0;
}