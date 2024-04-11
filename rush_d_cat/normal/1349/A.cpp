#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N], vis[N], mn[N];
vector<int> vec[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i ++) mn[i] = N;
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		//printf("# %d\n", i);
		for (int j = i; j < N; j += i) {
			mn[j] = min(mn[j], i); vis[j] = 1;
		}
	}
	for (int i = 1; i <= n; i ++) {
		int t = a[i];
		//printf("a = %d\n", t);
		while (t > 1) {
			int val = mn[t], cnt = 0;
			while (t % val == 0) {
				t /= val; cnt ++;
			}
			//printf("%d %d\n", val, cnt);
			vec[val].push_back(cnt);
		}
	}
	LL ans = 1;
	for (int i = 1; i < N; i ++) {
		for (int j = 0; j < 2; j ++) 
			if (vec[i].size() < n) 
				vec[i].push_back(0);
		sort(vec[i].begin(), vec[i].end());

		if (vec[i].size() >= 2) {
			//printf("i = %d\n", i);
			//for (auto x: vec[i]) printf("%d ", x);
			//printf("\n");
			int cnt = vec[i][1];
			int tmp = 1;
			for (int j = 1; j <= cnt; j ++) {
				tmp = tmp * i;
			}
			ans = ans * tmp;
		} 
	}
	printf("%lld\n", ans);
}