#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()

using ll = long long;
using i_i = tuple<int, int>;

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	union_find uf(N + M);
	while (Q--) {
		int i, j; scanf("%d%d", &i, &j);
		i--, j--;
		uf.unite(i, N + j);
	}
	int ans = 0;
	rep(k, N + M) {
		if (uf.root(k)) {
			ans++;
		}
	}
	ans--;
	cout << ans << endl;
}