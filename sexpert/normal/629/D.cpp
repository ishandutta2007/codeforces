#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	int l, r;
	ll mx;
	node *left, *right;

	node(int l, int r) : l(l), r(r), mx(0) {
		if(l < r) {
			int m = (l + r)/2;
			left = new node(l, m);
			right = new node(m + 1, r);
		}
	}
	void upd(int p, ll v) {
		if(r < p || p < l) return;
		if(l == r) { mx = v; return; }
		left->upd(p, v);
		right->upd(p, v);
		mx = max(left->mx, right->mx);
	}
	ll qry(int rl, int rr) {
		if(r < rl || rr < l)
			return -1;
		if(rl <= l && r <= rr)
			return mx;
		return max(left->qry(rl, rr), right->qry(rl, rr));
	}
};

int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) {
		ll r, h;
		cin >> r >> h;
		v[i] = r * r * h;
	}
	map<ll, int> fuck;
	vector<ll> sv, w;
	sv = v;
	w = v;
	sort(sv.begin(), sv.end());
	sv.erase(unique(sv.begin(), sv.end()), sv.end());
	for(int i = 0; i < sv.size(); i++)
		fuck[sv[i]] = i + 1;
	for(auto &x : v)
		x = fuck[x];
	/*for(int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << w[i] << " ";
	cout << endl;*/
	node tree(0, n);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int x = v[i];
		ll bef = tree.qry(0, x - 1);
		ll res = bef + w[i];
		ans = max(ans, res);
		tree.upd(x, res);
	}
	cout << fixed << setprecision(10) << acos(-1) * (double)ans << endl;
}