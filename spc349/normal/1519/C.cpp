#include <bits/stdc++.h>
using namespace std;

vector <int> all[200010];
long long sum[200010], ans[200010];
int a[200010], b[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) all[i].clear();
		for (int i = 1; i <= n; i++) ans[i] = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);
		for (int i = 0; i < n; i++) all[a[i]].push_back(b[i]);
		for (int i = 0; i < n; i++) {
			vector <int> &tmp = all[i];
			sort(tmp.rbegin(), tmp.rend());
			for (int j = 0; j < tmp.size(); j++) sum[j + 1] = sum[j] + tmp[j];
			for (int j = 1; j <= tmp.size(); j++) ans[j] += sum[(int)tmp.size() / j * j];
		}
		for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]); printf("\n");
	}
	return 0;
}