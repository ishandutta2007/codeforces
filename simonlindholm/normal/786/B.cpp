#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
vector<struct IvNode*> ivs;
struct IvNode {
	int lo, hi, mid;
	IvNode *left, *right;
	IvNode(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 == hi) {
			left = right = 0;
			mid = hi;
		} else {
			mid = (lo + hi) / 2;
			left = new IvNode(lo, mid);
			right = new IvNode(mid, hi);
		}
		ivs.push_back(this);
	}
	vector<pii> overlappingByStart;
	vector<pii> overlappingByEnd;
	void insert(int l, int r, int iv) {
		if (l >= hi || r <= lo) return;
		if (lo + 1 == hi) {
			assert(l == lo && r == hi);
			overlappingByStart.emplace_back(l, iv);
		} else {
			if (l < mid && mid < r) {
				overlappingByStart.emplace_back(l, iv);
				overlappingByEnd.emplace_back(r, iv);
			} else {
				left->insert(l, r, iv);
				right->insert(l, r, iv);
			}
		}
	}
	template<class F>
	void extractIntervals(int p, F f) {
		if (p >= hi || p < lo) return;
		if (p >= mid) {
			while (!overlappingByEnd.empty() && overlappingByEnd.back().first > p) {
				f(overlappingByEnd.back().second);
				overlappingByEnd.pop_back();
			}
		}
		if (p < mid) {
			while (!overlappingByStart.empty() && overlappingByStart.back().first <= p) {
				f(overlappingByStart.back().second);
				overlappingByStart.pop_back();
			}
		}
		if (left) {
			left->extractIntervals(p, f);
			right->extractIntervals(p, f);
		}
	}
};

static const ll inf = 1LL << 61;
static const ll deadinf = inf + 1;
int earth;

struct Node {
	int lo, hi;
	Node *left, *right;
	pli best;
	ll pushmin;
	Node(int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 == hi) {
			left = right = 0;
			best = (lo == earth ? pli(0LL, lo) : pli(inf, lo));
		} else {
			int mid = (lo + hi) / 2;
			left = new Node(lo, mid);
			right = new Node(mid, hi);
			best = min(left->best, right->best);
		}
		pushmin = inf;
	}

	void push() {
		if (pushmin < inf) {
			left->update(lo, hi, pushmin);
			right->update(lo, hi, pushmin);
			pushmin = inf;
		}
	}

	void kill(int ind) {
		if (ind < lo || ind >= hi) return;
		if (!left) {
			best = pli(deadinf, lo);
		} else {
			push();
			left->kill(ind);
			right->kill(ind);
			best = min(left->best, right->best);
		}
	}

	void update(int l, int r, ll val) {
		if (r <= lo || l >= hi) return;
		if (!left) {
			if (best.first != deadinf)
				best = min(best, pli(val, lo));
		} else if (l <= lo && hi <= r) {
			if (val < pushmin) {
				pushmin = val;
				if (best.first != deadinf && val < best.first)
					best.first = val;
			}
		} else {
			push();
			left->update(l, r, val);
			right->update(l, r, val);
			best = min(left->best, right->best);
		}
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q >> earth;
	--earth;
	vector<pil> fromr;
	vi fromrdead;
	IvNode* fromrange = new IvNode(0, N);
	vector<vector<pil>> normaled(N);
	vector<vector<pair<pii, ll>>> torange(N);
	int eid = 0;
	rep(i,0,Q) {
		int t;
		cin >> t;
		int u, v;
		ll cost;
		if (t == 1) {
			cin >> u >> v >> cost;
			--u;
			--v;
			normaled[u].push_back({v, cost});
		}
		else {
			int l, r;
			cin >> u >> l >> r >> cost;
			--u;
			--l;
			if (t == 2) {
				torange[u].emplace_back(pii(l, r), cost);
			}
			else {
				assert(t == 3);
				fromrange->insert(l, r, eid++);
				fromr.emplace_back(u, cost);
				fromrdead.emplace_back(false);
			}
		}
	}
	trav(iv, ivs) {
		sort(all(iv->overlappingByStart));
		reverse(all(iv->overlappingByStart));
		sort(all(iv->overlappingByEnd));
	}

	Node* tree = new Node(0, N);
	vector<ll> res(N, -1);
	while (tree->best.first < inf) {
		pli b = tree->best;
		ll dist = b.first;
		int ind = b.second;
		assert(dist >= 0);
		assert(res[ind] == -1);
		res[ind] = dist;
		tree->kill(ind);
		trav(pa, normaled[ind]) {
			tree->update(pa.first, pa.first+1, dist + pa.second);
		}
		trav(pa, torange[ind]) {
			tree->update(pa.first.first, pa.first.second, dist + pa.second);
		}
		fromrange->extractIntervals(ind, [&](int iv) {
			if (fromrdead[iv]++ == 0) {
				auto pa = fromr[iv];
				tree->update(pa.first, pa.first+1, dist + pa.second);
			}
		});
	}

	rep(i,0,N) cout << res[i] << ' ';
	cout << endl;

	exit(0);
}