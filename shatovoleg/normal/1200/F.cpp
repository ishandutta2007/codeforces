#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

vector<int> p, ans;
vector<int> used; 
int k = 1;

bool cycle_precalced(int v) {
	if (ans[v] != -1) {
		return 1;
	}
	if (used[v] == -1) {
		return false;
	}
	used[v] = -1;
	return cycle_precalced(p[v]);
}

int find_cycle(int v) {
	if (used[v] == 1) {
		return v;
	}
	used[v] = 1;
	return find_cycle(p[v]);
}

void precalc_cycle(int v) {
	int l = 1;
	for (int vv = p[v]; vv != v; vv = p[vv]) {
		++l;
	}
	set<int> d;
	for (int i = 0; i < l; ++i) {
		d.insert(v / k);
		v = p[v];
	}
	for (int i = 0; i < l; ++i) {
		ans[v] = len(d);
		v = p[v];
	}
}

int calc_ans(int v, bool need_check = true) {
	if (ans[v] != -1) {
		return ans[v];
	}
	if (!need_check || cycle_precalced(v)) {
		return ans[v] = calc_ans(p[v], false);
	}
	precalc_cycle(find_cycle(v));
	return ans[v] = calc_ans(p[v], false);
}

void run() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	vector<vector<int>> nxt(n);
	for (auto &v : nxt) {
		int m;
		cin >> m;
		k = lcm(k, m);
		v.resize(m);
		for (auto &x : v) {
			cin >> x;
			--x;
		}
	}
	for (auto &x : v) {
		x %= k;
		if (x < 0) {
			x += k;
		}
	}
	p.resize(n * k);
	ans.resize(n * k, -1);
	used.resize(n * k, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int vert = i * k + j;
			int val = (j + v[i]) % k;
			p[vert] = nxt[i][val % len(nxt[i])] * k + val;
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int v, x;
		cin >> v >> x;
		--v;
		x %= k;
		if (x < 0) {
			x += k;
		}
		cout << calc_ans(v * k + x) << endl;
	}
}