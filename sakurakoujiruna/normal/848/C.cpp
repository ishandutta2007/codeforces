#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 1e6L + 11;

int lb(int x) { return x & (-x); }
struct BIT {
	vi his;
	ll b[N];
	void clear() {
		while(his.size()) {
			b[his.back()] = 0;
			his.pop_back();
		}
	}
	void change(int p, int c) {
		for(int i = p; i < N; i += lb(i)) {
			his.pb(i);
			b[i] += c;
		}
	}
	ll query(int p) {
		ll r = 0;
		for(int i = p; i; i -= lb(i))
			r += b[i];
		return r;
	}
}bit;

struct Eve {
	int l, r, t, id;
	void w() { cout << l << ' ' << r << ' ' << t << ' ' << id << '\n'; }
	bool operator <(Eve e) const {
		return tie(r, t) < tie(e.r, e.t);
	}
}eve[N];

int a[N];
bool iq[N];
ll ans[N];

set <int> st[N];

void solve(int l, int r) {
	if(l + 1 == r) return;
	int m = (l + r) / 2;
	solve(l, m); solve(m, r);
	vector <Eve> v;
	for(int i = l; i < m; i ++) if(eve[i].t < 2)
		v.pb(eve[i]);
	for(int i = m; i < r; i ++) if(eve[i].t == 2)
		v.pb(eve[i]);
	sort(v.begin(), v.end());
	bit.clear();
	/*
	cout << "------\n";
	cout << l << ' ' << r << '\n';
	for(auto e : v) e.w();
	*/
	for(auto e : v) {
		if(e.t == 2)
			ans[e.id] += bit.query(N - 1) - bit.query(e.l - 1);
		else
			bit.change(e.l, (e.r - e.l) * e.t);
	}
}

int main() {
	ios :: sync_with_stdio(0);
	int n, m; cin >> n >> m;
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		st[a[i]].insert(i);
		auto it = st[a[i]].lower_bound(i);
		if(it != st[a[i]].begin()) {
			it --;
			eve[++ cnt] = {*it, i, 1, 0};
		}
	}
	for(int i = 1; i <= m; i ++) {
		int t; cin >> t;
		if(t == 2) {
			int l, r; cin >> l >> r;
			eve[++ cnt] = {l, r, 2, i};
			iq[i] = 1;
		} else {
			int p, x; cin >> p >> x;
			int c = a[p];
			auto it = st[c].lower_bound(p);
			
			int l = -1, r = -1;
			
			if(it != st[c].begin()) {
				-- it; l = *it;
				eve[++ cnt] = {*it, p, -1, 0};
			}
			it = st[c].lower_bound(p); ++ it;
			if(it != st[c].end()) {
				r = *it;
				eve[++ cnt] = {p, *it, -1, 0};
			}
			if(~l && ~r)
				eve[++ cnt] = {l, r, 1, 0};
			st[c].erase(p);
			st[x].insert(p);
			a[p] = x;
			
			l = -1, r = -1;
			it = st[x].lower_bound(p);
			if(it != st[x].begin()) {
				-- it; l = *it;
				eve[++ cnt] = {*it, p, 1, 0};
			}
			it = st[x].lower_bound(p); ++ it;
			if(it != st[x].end()) {
				r = *it;
				eve[++ cnt] = {p, *it, 1, 0};
			}
			if(~l && ~r)
				eve[++ cnt] = {l, r, -1, 0};
		}
	}
	/*
	for(int i = 1; i <= cnt; i ++)
		eve[i].w();
	*/
	solve(1, cnt + 1);
	
	for(int i = 1; i <= n; i ++) if(iq[i])
		cout << ans[i] << '\n';
	
	return 0;
}