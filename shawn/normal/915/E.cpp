#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
	ll l, r;
	mutable ll v;
	node(ll l, ll r, ll v) : l(l), r(r), v(v) {}
	bool operator < (const node& t) const {
		return l < t.l;
	}
};

set <node> tr;

auto split(ll pos) {
	auto it = tr.lower_bound(node(pos, 0, 0));
	if (it != tr.end() && it->l == pos) return it;
	it --;
	ll l = it->l, r = it->r, v = it->v;
	tr.erase(it);
	tr.insert(node(l, pos - 1, v));
	return tr.insert(node(pos, r, v)).first;
}

ll sum = 0;
void assign(ll l, ll r, ll v) {
	ll tot = 0, len = 0;
	auto end = split(r + 1), begin = split(l);
	for (auto it = begin; it != end; it ++) {
		len += it->r - it->l + 1;
		tot += it->v * (it->r - it->l + 1);
	}
	tr.erase(begin, end);
	tr.insert(node(l, r, v));
	if (v == 1) sum += (len - tot);
	else sum -= tot;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	tr.insert(node(1, sum = n, 1));
	for (int i = 1; i <= q; i ++) {
		ll l, r, k;
		cin >> l >> r >> k;
		assign(l, r, k == 1 ? 0 : 1);
		cout << sum << "\n";
	}
	return 0;
}