#include <set>
#include <iostream>
using namespace std;
int n, m, q, a, b, par[400009];
int root(int x) {
	if (x == par[x]) return x;
	return par[x] = root(par[x]);
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 0; i < n + m; ++i) par[i] = i;
	for (int i = 0; i < q; ++i) {
		cin >> a >> b; --a, --b;
		par[root(a)] = root(b + n);
	}
	set<int> s;
	for (int i = 0; i < n + m; ++i) s.insert(root(i));
	cout << (int)s.size() - 1 << '\n';
	return 0;
}