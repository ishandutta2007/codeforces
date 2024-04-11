#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1 << 29;

struct Node {
	Node *l = 0, *r = 0;
	int val, lo, hi, y, c = 1;
	int istmp = 0;
	map<int, int> mem;
	Node() : y(rand()) { istmp = 1; }
	Node(int val) : y(rand()) { init(val); }
	void init(int val) {
		this->val = val;
		hi = val;
		lo = val - 1;
	}
	void recalc();
};
Node nodes2[1000];
int nind = 0;

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() {
	c = cnt(l) + cnt(r) + 1;
	hi = r ? r->hi : val;
	mem.clear();
	lo = INF;
	if (l) {
		lo = l->lo;
	}
	// lo + cnt(l) + 1 <= val
	// lo <= val - cnt(l) - 1
	lo = min(lo, val - cnt(l) - 1);
	// lo + cnt(l) + 1 <= r->lo
	if (r) {
		lo = min(lo, r->lo - cnt(l) - 1);
	}
}

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int v) {
	if (!n) return {};
	if (n->val >= v) { // "n->val >= v" for lower_bound(v)
		auto pa = split(n->l, v);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, v);
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

pair<Node*, Node*> split2(Node* n, int rating) {
	if (!n) return {};
	Node* nn = &nodes2[nind++];
	nn->init(n->val);
	if (rating - cnt(n->l) <= n->val) { // we won't downvote, let left child do that
		auto pa = split2(n->l, rating);
		nn->l = pa.second;
		nn->r = n->r;
		nn->recalc();
		return {pa.first, nn};
	}
	rating -= cnt(n->l) + 1;
	auto pa = split2(n->r, rating);
	nn->l = n->l;
	nn->r = pa.first;
	nn->recalc();
	return {nn, pa.second};
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

Node* ins(Node* t, Node* n) {
	auto pa = split(t, n->val);
	return merge(merge(pa.first, n), pa.second);
}

int rec(Node* n, int rat) {
	if (!n) return rat;
	if (rat <= n->lo)
		return rat + cnt(n);
	if (rat >= n->hi)
		return rat;
	int dummy;
	int& out = (n->istmp ? dummy : n->mem[rat]);
	if (!n->istmp && out) return out - INF;
	rat = rec(n->l, rat);
	if (rat < n->val) rat++;
	rat = rec(n->r, rat);
	out = rat + INF;
	return rat;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi a(N);
	rep(i,0,N) cin >> a[i];
	vector<Node> nodes;
	nodes.reserve(N);
	rep(i,0,N) nodes.emplace_back(a[i]);
	Node* t = 0;
	rep(i,0,N) {
		nind = 0;
		t = ins(t, &nodes[i]);
		auto pa = split2(t, 0);
		int rat = -cnt(pa.first);
		rat = rec(pa.second, rat);
		cout << rat << '\n';
	}
	exit(0);
}