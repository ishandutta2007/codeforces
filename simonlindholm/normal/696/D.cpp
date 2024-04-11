#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const ll ninf = 1-(1LL << 62);

struct AhoCorasick {
	enum {alpha = 26, first = 'a'};
	struct Node {
		int back, next[alpha], start = -1, end = -1;
		int summatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vector<int> backp;
	void insert(string& s, int j, int val) {
		assert(!s.empty());
		int n = 0;
		trav(c, s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;
		N[n].summatches += val;
	}
	AhoCorasick(vector<pair<string,int>>& pat) {
		N.emplace_back(-1);
		rep(i,0,sz(pat)) insert(pat[i].first, i, pat[i].second);
		N[0].back = sz(N);
		N.emplace_back(0);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].summatches += N[y].summatches;
					q.push(ed);
				}
			}
		}
	}

	ll score(string word) {
		int n = 0;
		ll count = 0;
		trav(c, word) {
			n = N[n].next[c - first];
			count += N[n].summatches;
		}
		return count;
	}
};

int N;
typedef vector<vector<ll>> D;
D mdists(const D& a, const D& b) {
	D ret(N, vector<ll>(N));
	rep(i,0,N) rep(j,0,N) {
		ll r = ninf;
		rep(k,0,N) {
			r = max(r, a[i][k] + b[k][j]);
		}
		if (r < 0) r = ninf;
		ret[i][j] = r;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	ll L;
	cin >> N >> L;
	vector<pair<string, int>> w(N);
	rep(i,0,N)
		cin >> w[i].second;
	rep(i,0,N)
		cin >> w[i].first;
	AhoCorasick ac(w);

// cerr << ac.score("artart") << endl;

	N = sz(ac.N);
	D dists(N, vector<ll>(N, ninf));
	rep(i,0,N) {
		rep(c,0,26) {
			int j = ac.N[i].next[c];
			int w = ac.N[j].summatches;
			dists[i][j] = w;
		}
	}

// cout << ac.N[0].next[0] << endl;
// cout << ac.N[ac.N[0].next[0]].next['r' - 'a'] << endl;

	// rep(i,0,N) {
		// rep(j,0,N) cout << (dists[i][j] == ninf ? -1 : dists[i][j]) << ' ';
		// cout << endl;
	// }
	// cout << endl;

	D cdists(N, vector<ll>(N, ninf));
	rep(i,0,N) cdists[i][i] = 0;

	for (ll b = 1; L; b <<= 1) {
		if (b & L) {
			L &= ~b;
			cdists = mdists(cdists, dists);
		}
		dists = mdists(dists, dists);
	}

	ll res = ninf;
	rep(i,0,N)
		res = max(res, cdists[0][i]);
	cout << res << endl;

	exit(0);
}