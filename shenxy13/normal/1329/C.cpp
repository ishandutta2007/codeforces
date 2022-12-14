#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
inline int cmp(ii a, ii b) {
	if (a.first > b.first) return a.second;
	else return b.second;
}
inline int op(int i) {
	if (i == 0) return 10000000;
	else return i;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, g;
		scanf("%d %d", &h, &g);
		int a[1 << (h + 1)];
		fill_n(a, 1 << (h + 1), 0);
		for (int i = 1; i < (1 << h); ++i) scanf("%d", &a[i]);
		priority_queue<ii> pq;
		pq.push(ii(a[1], 1));
		vector<int> ans;
		while (!pq.empty()) {
			ii k = pq.top();
			pq.pop();
			int i = k.second;
			while (a[i] != 0) i = cmp(ii(a[i * 2], i * 2), ii(a[i * 2 + 1], i * 2 + 1));
			if (i / 2 < (1 << g)) {
				i = k.second;
				while (max(a[i * 2], a[i * 2 + 1]) != 0) pq.push(min(ii(op(a[i * 2]), i * 2), ii(op(a[i * 2 + 1]), i * 2 + 1))), i = cmp(ii(a[i * 2], i * 2), ii(a[i * 2 + 1], i * 2 + 1));
			} else {
				i = k.second;
				while (a[i] != 0) a[i] = max(a[i * 2], a[i * 2 + 1]), i = cmp(ii(a[i * 2], i * 2), ii(a[i * 2 + 1], i * 2 + 1));
				ans.push_back(k.second);
				if (a[k.second] != 0) pq.push(ii(a[k.second], k.second));
			}
		}
		long long a2 = 0;
		for (int i = 1; i < (1 << g); ++i) a2 += a[i];
		printf("%lld\n", a2);
		for (int i: ans) printf("%d ", i);
		printf("\n");
	}
	return 0;
}