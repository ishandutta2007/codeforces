#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t, n, a[N], dis[N], mn[N];
vector<int> vec[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			vec[i].clear();
			vec[i].push_back(0); vec[i].push_back(n + 1);
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			vec[a[i]].push_back(i);
		}
		for (int i = 1; i <= n; i ++) {
			sort(vec[i].begin(), vec[i].end());
		}

		for (int i = 1; i <= n; i ++) mn[i] = 1e9;
		for (int i = 1; i <= n; i ++) {
			dis[i] = 0; 
			for (int j = 0; j + 1 < vec[i].size(); j ++) {
				dis[i] = max(vec[i][j+1] - vec[i][j], dis[i]);
			}
			// printf("dis[%d] = %d\n", i, dis[i]);
			if (dis[i] <= n)
				mn[dis[i]] = min(mn[dis[i]], i);
		}
		for (int i = 1; i <= n; i ++) {
			if (i >= 2) mn[i] = min(mn[i-1], mn[i]);
			printf("%d ", mn[i] > n ? -1 : mn[i]);
		}
		printf("\n");
	}	
}