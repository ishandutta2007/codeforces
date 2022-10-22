#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e5 + 10;
const ll INF = 8e18;

struct CHT {
	vector<pair<ll, pll>> vec;

	inline ll insec(pll a, pll b) {
		if (a.X == b.X) //
			return a.Y <= b.Y ? INF : -INF;
		if (a.X > b.X) swap(a, b);
		return (a.Y - b.Y + (a.Y <= b.Y ? 0 : 1) * (a.Y - b.Y - 1)) / (b.X - a.X);
	}

	inline void add(pll line) {
		while (!vec.empty()) {
			ll x = insec(vec.back().Y, line);
			if (x <= vec.back().X) vec.pop_back();
			else {
				vec.push_back({x, line});
				return;
			}
		}

		vec.push_back({-INF, line});
	}

	inline void build(vector<pll> lines) {
		sort(all(lines), greater<pll>());
		for (pll line : lines) add(line);
	}

	inline ll chMax(ll x) {
		auto it = prev(upper_bound(all(vec), make_pair(x, pll(INF, INF))));
		return it -> Y.X * x + it -> Y.Y;
	}
};

CHT sg[MAXN];
ll ps[MAXN], n, A[MAXN], q;

void build(int l = 1, int r = n, int v = 1) {
	vector<pll> vec;
	for (int i = l; i <= r; i++)
		vec.push_back({A[i], i * A[i] - ps[i]});
	sg[v].build(vec);

	if (l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
}

ll query(int ql, int qr, ll x, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return INF;
	if (ql <= l && qr >= r) return sg[v].chMax(x);

	int mid = (l + r) >> 1;
	return min(query(ql, qr, x, l, mid, v << 1),
			query(ql, qr, x, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
	}

	build();
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << query(j - i + 1, j, i - j) + ps[j] << endl; //
	}
	return 0;
}