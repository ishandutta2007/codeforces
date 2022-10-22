#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
const int LOGN = 20;

const int SQ = 300;

struct Query {
	int tp, x, y;
};

struct Rollback {
	int v, pv, rv;
};

int n, m;	
Query qs[N];
int sz_q = 0;

vector <int> p, r;
Rollback rb[N];
int sz_r = 0;


set <pair <int, int> > edges, exist;

int get(int v, bool save = false) {
	if (p[v] == v) {
		return v;
	}
	if (save) {
		rb[sz_r++] = {v, p[v], r[v]};
	}
	return p[v] = get(p[v], save);
}

void uni(int v, int u, bool save = false) {
	v = get(v, save);
	u = get(u, save);
	if (v == u) return;
	if (save) {
		rb[sz_r++] = {v, p[v], r[v]};
		rb[sz_r++] = {u, p[u], r[u]};
	}
	if (r[v] > r[u]) swap(v, u);
	if (r[v] == r[u]) r[u]++;
	p[v] = u;
}

int last = 0;

void update() {
	p.assign(n, 0);
	iota(p.begin(), p.end(), 0);
	r.assign(n, 0);
	for (int i = 0; i < sz_q; i++) {
		auto q = qs[i];	
		if (q.tp == 1) {
			for (int l = 0; l < 2; l++) {
				int v = (q.x + l - 1) % n, u = (q.y + l - 1) % n;
				if (v > u) swap(v, u);
				if (edges.find({v, u}) != edges.end()) {
					edges.erase({v, u});
					exist.insert({v, u});
				}
			}
		}
	}
	for (auto e : edges) {
		uni(e.first, e.second);
	}
	for (int i = 0; i < sz_q; i++) {
		auto q = qs[i];
		int v = (q.x + last - 1) % n, u = (q.y + last - 1) % n;
		if (q.tp == 1) {
			if (v > u) swap(v, u);
			if (exist.find({v, u}) != exist.end()) {
				exist.erase({v, u});
			} else {
				exist.insert({v, u});
			}
		} else {
			for (auto e : exist) {
				uni(e.first, e.second, true);
			}
			if (get(v, true) != get(u, true)) {
				last = 0;
			} else {
				last = 1;
			}
			cout << last;
			for (int i = sz_r - 1; i >= 0; i--) {
				p[rb[i].v] = rb[i].pv;
				r[rb[i].v] = rb[i].rv;
			}
			sz_r = 0;
		}
	}
	for (auto e : exist) {
		edges.insert(e);
	}
	exist.clear();
	sz_q = 0;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tp, x, y;
		cin >> tp >> x >> y;
		qs[sz_q++] = {tp, x, y};
		if (sz_q == SQ) {
			update();
		}
	}
	if (sz_q) {
		update();
	}
	cout << "\n";
}