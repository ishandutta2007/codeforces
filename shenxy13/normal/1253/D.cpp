#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct UFDS {
	vector<int> parent, rankof, maxnod;
	UFDS(int n) {
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
			rankof.push_back(0);
			maxnod.push_back(i);
		}
	}
	int find_parent(int i) {
		if (parent[i] == i) return i;
		else return parent[i] = find_parent(parent[i]);
	}
	inline bool union_set(int p, int q) {
		int pp = find_parent(p), pq = find_parent(q);
		if (pp == pq) return false;
		if (rankof[pp] == rankof[pq]) {
			++rankof[pp];
			parent[pq] = pp;
			maxnod[pp] = max(maxnod[pp], maxnod[pq]);
		} else if (rankof[pp] > rankof[pq]) {
			parent[pq] = pp;
			maxnod[pp] = max(maxnod[pp], maxnod[pq]);
		} else {
			parent[pp] = pq;
			maxnod[pq] = max(maxnod[pp], maxnod[pq]);
		}
		return true;
	}
};
int main() {
	int n, m, u, v;
	long long ans = 0;
	scanf("%d %d", &n, &m);
	UFDS mysets(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		mysets.union_set(u - 1, v - 1);
	}
	for (int i = 0; i < n; ++i) {
		int tg = mysets.maxnod[mysets.find_parent(i)];
		for (++i; i < tg; ++i) {
			if (mysets.union_set(i - 1, i)) ++ans;
			tg = max(tg, mysets.maxnod[mysets.find_parent(i)]);
		}
		--i;
	}
	printf("%lld", ans);
	return 0;
}