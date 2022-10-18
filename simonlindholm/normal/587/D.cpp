#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void add_clause(int a_index, bool a_value, int b_index, bool b_value) {
		int a = 2*a_index + a_value, b = 2*b_index + b_value;
		gr[a^1].push_back(b);
		gr[b^1].push_back(a);
	}
	void set_value(int index, bool value) { // (optional)
		add_clause(index, value, index, value);
	}

	void at_most_one(const vi& li, bool val=1) { // (optional)
		if (sz(li) <= 1) return;
		int cur = li[0];
		rep(i,2,sz(li)) {
			int next = add_var();
			add_clause(cur, !val, li[i], !val);
			add_clause(cur, !val, next, val);
			add_clause(li[i], !val, next, val);
			cur = next;
		}
		add_clause(cur, !val, li[1], !val);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low; 
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main() {
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vi> ed(N);
	vector<map<int, vi> > ced(N);
	vi times;
	rep(i,0,M) {
		int u, v, c, t;
		cin >> u >> v >> c >> t;
		--u, --v;
		times.push_back(t);
		ed[u].emplace_back(i);
		ed[v].emplace_back(i);
		ced[u][c].push_back(i);
		ced[v][c].push_back(i);
	}
	TwoSat* ts = 0;
	auto works = [&](int lim) {
		delete ts;
		ts = new TwoSat(M);
		rep(i,0,M)
			if (times[i] > lim) ts->set_value(i, false);
		rep(i,0,N) {
			ts->at_most_one(ed[i], 1);
			trav(pa, ced[i])
				ts->at_most_one(pa.second, 0);
		}
		return ts->solve();
	};
	int hi = 1e9;
	if (!works(hi)) {
		cout << "No" << endl;
	}
	else {
		int lo = -1;
		while (lo + 1 < hi) {
			int mid = (hi + lo) / 2;
			if (works(mid))
				hi = mid;
			else
				lo = mid;
		}
		works(hi);
		cout << "Yes" << endl;
		cout << hi << ' ';
		vi dest;
		rep(i,0,M) if (ts->values[i]) dest.push_back(i+1);
		cout << sz(dest) << endl;
		PR(dest);
	}
	exit(0);
}