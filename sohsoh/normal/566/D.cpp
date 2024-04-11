#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, q, par[MAXN], H[MAXN];
set<pll> st;

int find_set(int v) {
	if (v == par[v]) return v;
	return par[v] = find_set(par[v]);//
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a == b) return;
	if (H[a] < H[b]) swap(a, b);
	par[b] = a;
	if (H[a] == H[b]) H[a]++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		st.insert({i, i});
		par[i] = i;
	}

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) union_sets(x, y);
		else if (t == 2) {
			auto it = st.lower_bound({x + 1, -1});
			it--;
			int t_x = it -> X, t_y;
			while (it != st.end() && it -> X <= y) {
				t_y = it -> Y;
				pll e = *it;
				st.erase(e);
				union_sets(t_x, e.X);
				it = st.upper_bound(e);
			}

			st.insert({t_x, t_y});
		} else {
			if (find_set(x) == find_set(y)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}