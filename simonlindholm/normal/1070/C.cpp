#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	Node *l = 0, *r = 0;
	ll cost, count;
	ll sumcost, sumcount;
	int y, c = 1;
	Node(ll cost = -100, ll count = -100) : cost(cost), count(count),
		sumcost(cost * count), sumcount(count),  y(rand()) {}
	void recalc();
	pair<ll, ll> pa() { return {cost, count}; }
};

int cnt(Node *n) { return n ? n->c : 0; }
void Node::recalc() {
	c = cnt(l) + cnt(r) + 1;
	sumcost = cost * count + (l ? l->sumcost : 0) + (r ? r->sumcost : 0);
	sumcount = count + (l ? l->sumcount : 0) + (r ? r->sumcount : 0);
}

pair<Node*, Node*> split(Node* n, pair<ll, ll> k) {
	if (!n) return {};
	if (n->pa() >= k) {
		auto pa = split(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, k);
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

pair<Node*, Node*> split2(Node* n, int k) {
	if (!n) return {};
	if (cnt(n->l) >= k) {
		auto pa = split2(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split2(n->r, k - cnt(n->l) - 1);
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		l->recalc();
		return l;
	} else {
		r->l = merge(l, r->l);
		r->recalc();
		return r;
	}
}

Node* add(Node* n, Node *ne) {
	auto pa = split(n, ne->pa());
	return merge(merge(pa.first, ne), pa.second);
}

Node* rem(Node* n, Node *ne) {
	auto pa = split(n, ne->pa());
	auto pa2 = split2(pa.second, 1);
	return merge(pa.first, pa2.second);
}

ll query(Node* n, int& K) {
	if (!n || !K) return 0;
	if (n->sumcount <= K) {
		K -= n->sumcount;
		return n->sumcost;
	}
	ll res = query(n->l, K);
	if (K) {
		if (K >= n->count) {
			K -= n->count;
			res += n->count * n->cost;
			res += query(n->r, K);
		} else {
			res += K * n->cost;
			K = 0;
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	int N, K, M;
	cin >> N >> K >> M;
	vector<vi> ev(N + 1);
	vector<Node> nodes(M);
	rep(i,0,M) {
		int left, right, avail, cost;
		cin >> left >> right >> avail >> cost;
		nodes[i] = Node(cost, avail);
		ev[left - 1].emplace_back(i);
		ev[right].emplace_back(~i);
	}
	Node *tr = nullptr;

	ll oldans = -1;
	ll ans = 0;
	rep(i,0,N) {
		trav(ind, ev[i]) {
			oldans = -1;
			if (ind >= 0) {
				Node *node = &nodes[ind];
				tr = add(tr, node);
			}
			else {
				Node *node = &nodes[~ind];
				tr = rem(tr, node);
			}
		}

		if (oldans == -1) {
			int k2 = K;
			oldans = query(tr, k2);
		}
		ans += oldans;
	}
	cout << ans << endl;
}