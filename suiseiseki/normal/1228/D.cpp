#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int ans[maxn];
vector<int> G[maxn];
int cnt[10];
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (auto y : G[1]) {
		ans[y] = 2;
	}
	for (int i = 1; i <= n; i++) {
		if(ans[i] == 0) {
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if(ans[i] == 2) {
			for (auto y : G[i]) {
				if(ans[y] == 2) {
					ans[y] = 3;
				}
			}
			break;
		}
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		cnt[ans[i]]++;
		for (auto y : G[i]) {
			if(ans[y] == ans[i]) {
				flag = 1;
			}
		}
	}
	int tot = cnt[1] * cnt[2] + cnt[2] * cnt[3] + cnt[3] * cnt[1];
	if(flag == 1 || cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0 || tot != m) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}