#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

struct Node {
	int val;
	Node *l, *r;
	Node() {
		val = 0;
		l = r = nullptr;
	}
};

/*void make_childs(Node *v) {
	if (v->l == nullptr) v->l = new Node();
	if (v->r == nullptr) v->r = new Node();
}*/

inline int getVal(Node *v) {
	return (v == nullptr ? 0 : v->val);
}

void add(Node *v, ll l, ll r, ll pos) {
	if (r - l == 1) {
		v->val++;
		return;
	}
	ll m = (l + r) / 2;	
	if (pos < m) {
		if (v->l == nullptr) v->l = new Node();
		add(v->l, l, m, pos);
	} else {
		if (v->r == nullptr) v->r = new Node();
		add(v->r, m, r, pos);
	}
	v->val = getVal(v->l) + getVal(v->r);
}

int getSum(Node *v, ll l, ll r, ll L, ll R) {
	if (v == nullptr) return 0;
	if (l >= R || L >= r) return 0;
	if (L <= l && r <= R) return v->val;
	ll m = (l + r) / 2;	
	return getSum(v->l, l, m, L, R) + getSum(v->r, m, r, L, R);
}

int a[N];
void solve() {
	int n;
	ll t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll sum = 0, ans = 0;
	Node *root = new Node();
	add(root, -INF, INF, 0);

	for (int i = 0; i < n; i++) {
		sum += a[i];
		//cout << "ask " << sum - t + 1 << " +";
		ll cur = getSum(root, -INF, INF, sum - t + 1, INF);
		//cout << " = " << cur << "\n";
		ans += cur;
		add(root, -INF, INF, sum);
		//cout << "add " << sum << "\n";
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}