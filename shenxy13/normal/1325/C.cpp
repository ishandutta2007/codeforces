#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
vector<ii> adjlist[100000];
int ans[99999], cnt = 3;
bool settle = false;
void dfs(int v, int p) {
	if (!settle && adjlist[v].size() > 2) {
		--cnt;
		settle = true;
		int calc = 0;
		for (ii i: adjlist[v]) {
			if (i.first == p) ans[i.second] = 0;
			else {
				ans[i.second] = (calc < 2 ? ++calc : cnt++);
				dfs(i.first, v);
			}
		}
	} else {
		for (ii i: adjlist[v]) {
			if (i.first == p) continue;
			ans[i.second] = cnt++;
			dfs(i.first, v);
		}
	}
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &a, &b);
		adjlist[a - 1].push_back(ii(b - 1, i));
		adjlist[b - 1].push_back(ii(a - 1, i));
	}
	if (n < 4) {
		for (int i = 0; i < n - 1; ++i) printf("%d\n", i);
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (adjlist[i].size() == 1) {
			dfs(i, -1);
			for (int j = 0; j < n - 1; ++j) printf("%d\n", ((ans[j] > n - 2) ? (ans[j] - n + 1) : ans[j]));
			return 0;
		}
	}
}