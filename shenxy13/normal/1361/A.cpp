#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<int> adjlist[n], ans;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		adjlist[a - 1].push_back(b - 1);
		adjlist[b - 1].push_back(a - 1);
	}
	ii t[n];
	int rt[n];
	for (int i = 0; i < n; ++i) scanf("%d", &t[i].first), t[i].second = i, rt[i] = t[i].first;
	sort(t, t + n, greater<ii>());
	for (int i = 0; i < n; ++i) {
		a = t[i].first, b = t[i].second;
		set<int> adjs;
		for (int j: adjlist[b]) {
			if (rt[j] < a) adjs.insert(rt[j]);
			else if (rt[j] == a) {
				printf("-1");
				return 0;
			}
		}
		if (adjs.size() != a - 1) {
			printf("-1");
			return 0;
		} else ans.push_back(b + 1), rt[b] = n + 1;
	}
	for (int i = n - 1; i >= 0; --i) printf("%d ", ans[i]);
	return 0;
}