#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		sort(begin(arr), end(arr));
		int ans = 0, cLeader = 0;
		while (cLeader < n) {
			int groupLast = cLeader;
			while (groupLast < n && arr[groupLast] > groupLast - cLeader + 1) ++groupLast;
			if (groupLast < n) {
				 ++ans;
			}
			cLeader = groupLast + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}