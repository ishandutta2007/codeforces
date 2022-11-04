#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], cnt[N], flag[N], crr;
void solve() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", a + i);
		cnt[a[i]] ++;
	}
	vector<int> ans;
	for(int i = 0, j; i < n; i = j) {
		int tmp = 0;
		while(cnt[tmp]) tmp ++;
		crr ++;
		int k = 0;
		for(j = i; ; ) {
			cnt[a[j]] --;
			if(a[j] < tmp && flag[a[j]] != crr) {
				flag[a[j]] = crr;
				k ++;
			}
			j ++;
			if(k == tmp) {
				break;
			}
		}
		ans.push_back(tmp);
	}
	printf("%d\n", ans.size());
	for(auto r : ans) {
		printf("%d ", r);
	}
	puts("");
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		solve();
	}
	return 0;
}