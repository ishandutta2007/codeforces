#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> ii;
struct UFDS {
	vector<ii> parent;
	vector<int> stsize;
	vector<ii> rb;
	UFDS(int N) {
		for (int i = 0; i < N; ++i) parent.push_back(ii(i, 0)), stsize.push_back(1);
	}
	ii find_parent(int i) {
		if (parent[i].first == i) return parent[i];
		ii ans = find_parent(parent[i].first);
		return ii(ans.first, (parent[i].second + ans.second) % 2);
	}
	bool union_set(int p, int q) {
		ii pp = find_parent(p), qq = find_parent(q);
		if (pp.first == qq.first) return pp.second != qq.second;
		if (stsize[pp.first] < stsize[qq.first]) swap(pp, qq);
		parent[qq.first] = ii(pp.first, pp.second == qq.second);
		stsize[pp.first] += stsize[qq.first];
		rb.push_back(ii(pp.first, qq.first));
		return true;
	}
	void rollback() {
		while (!rb.empty()) {
			ii x = rb.back();
			rb.pop_back();
			parent[x.second] = ii(x.second, 0);
			stsize[x.first] -= stsize[x.second];
		}
	}
};
int main() {
	int n, m, k, a, b, use = 0;
	long long ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	int c[n];
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	vector<int> adjlist[n];
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		if (c[a - 1] > c[b - 1]) swap(a, b);
		adjlist[a - 1].push_back(b - 1);
	}
	UFDS sets(n);
	bool bip[k];
	fill_n(bip, k, true);
	for (int i = 0; i < n; ++i) {
		for (int j: adjlist[i]) {
			if (c[i] == c[j]) bip[c[i] - 1] &= sets.union_set(i, j);
		}
	}
	map< int, vector<ii> > adj[k];
	sets.rb.clear();
	for (int i = 0; i < k; ++i) use += bip[i];
	for (int i = 0; i < n; ++i) {
		for (int j: adjlist[i]) {
			if (c[i] == c[j] || !bip[c[i] - 1] || !bip[c[j] - 1]) continue;
			adj[c[i] - 1][c[j] - 1].push_back(ii(i, j));
		}
	}
	for (int i = 0; i < k; ++i) {
		if (!bip[i]) continue;
		--use;
		ans += use;
		for (auto &j: adj[i]) {
			for (ii &l: j.second) {
				if (!sets.union_set(l.first, l.second)) {
					--ans;
					break;
				}
			}
			sets.rollback();
		}
	}
	printf("%lld", ans);
	return 0;
}