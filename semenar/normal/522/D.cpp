#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(X) X.begin(), X.end()
#define sz(X) ((int)X.size())
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;

const int INT_INF = 2e9;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

struct segtree {
	int n;
	vi nodes;

	segtree() {}
	segtree(int n) {
		resize(n);
	}

	void resize(int n) {
		this->n = n;
		nodes.resize(4 * n, INT_INF);
	}
	size_t size() {
		return n;
	}

	void upd(int v) {
		nodes[v] = min(nodes[2 * v], nodes[2 * v + 1]);
	}

	void set(int l, int r, int v, int pos, int x) {
		if (r == l + 1) nodes[v] = x;
		else {
			int med = (l + r) / 2;
			if (pos < med) set(l, med, 2 * v, pos, x);
			else set(med, r, 2 * v + 1, pos, x);
			upd(v);
		}
	}
	void set(int pos, int x) {
		set(0, n, 1, pos, x);
	}

	int get(int l, int r, int v, int ql, int qr) {
		if (r <= ql || qr <= l) return INT_MAX;
		if (r <= qr && ql <= l) return nodes[v];
		int med = (l + r) / 2;
		return min(get(l, med, 2 * v, ql, qr), get(med, r, 2 * v + 1, ql, qr));
	}
	int get(int l, int r) {
		return get(0, n, 1, l, r + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vpii queries(m);
	for (int i = 0; i < m; i++) {
		cin >> queries[i].fst >> queries[i].snd;
		queries[i].fst--;
		queries[i].snd--;
	}

	vpii sorted_queries(m);
	for (int i = 0; i < m; i++) sorted_queries[i] = mp(queries[i].snd, i);
	sort(all(sorted_queries));

	int pos = -1;
	map<int, int> last_seen;

	segtree st(n);

	vi q_ans(m);

	for (auto q : sorted_queries) {
		int i = q.snd;
		while (pos < queries[i].snd) {
			pos++;
			if (last_seen.count(a[pos])) st.set(last_seen[a[pos]], pos - last_seen[a[pos]]);
			last_seen[a[pos]] = pos;
		}
		q_ans[i] = st.get(queries[i].fst, queries[i].snd);
		if (q_ans[i] == INT_INF) q_ans[i] = -1;
	}

	for (auto ans : q_ans) cout << ans << endl;
}