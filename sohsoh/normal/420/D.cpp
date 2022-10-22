// Sohsoh84 :)))
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e6 + 10;

tree<pair<int, pll>, null_type, less<pair<int, pll>>, 
	rb_tree_tag, tree_order_statistics_node_update> st;
int n, m, ans[MAXN];
bool used[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		st.insert({i, {0, i}});

	int ind = 0;
	while (m--) {
		int x, y;
		cin >> y >> x;

		auto it = st.find_by_order(x - 1);
		pair<int, pll> e = *it;
		st.erase(it);

		if (e.Y.X == 0) {
			if (used[y]) return cout << -1 << endl, 0;
			used[y] = true;
			ans[e.Y.Y] = y;
			e.Y.X = y;
		} else if (e.Y.X != y) return cout << -1 << endl, 0;

		e.X = ind--;
		st.insert(e);
	}

	int j = 1;
	for (int i = 1; i <= n; i++) {
		if (ans[i]) cout << ans[i] << sep;
		else {
			while (used[j]) j++;
			cout << j << sep;
			j++;
		}
	}

	cout << endl;
	return 0;
}