#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		int b[n], a[n];
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		set<ii> occ;
		vector<int> pos[n + 1], unmatch;
		fill_n(a, n, -1);
		for (int i = 0; i < n; ++i) pos[b[i] - 1].push_back(i);
		for (int i = 0; i <= n; ++i) occ.insert(ii(pos[i].size(), i));
		ii k1 = *occ.begin();
		for (int i = 0; i < x; ++i) {
			ii k = *--occ.end();
			occ.erase(--occ.end());
			a[pos[k.second].back()] = b[pos[k.second].back()];
			pos[k.second].pop_back();
			--k.first;
			occ.insert(k);
		}
		ii k2 = *--occ.end();
		for (ii i: occ) {
			for (int j: pos[i.second]) unmatch.push_back(j);
		}
		for (int i = 0; i < unmatch.size(); ++i) {
			if (b[unmatch[i]] != b[unmatch[(i + k2.first) % unmatch.size()]] && y > x) {
				a[unmatch[i]] = b[unmatch[(i + k2.first) % unmatch.size()]];
				--y;
			}
		}
		if (y == x) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				if (a[i] == -1) a[i] = k1.second + 1;
			}
			printf("%d", a[0]);
			for (int i = 1; i < n; ++i) printf(" %d", a[i]);
			printf("\n");
		} else printf("NO\n");
	}
	return 0;
}