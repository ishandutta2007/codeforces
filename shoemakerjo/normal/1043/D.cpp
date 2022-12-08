#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 100010

int n, m;
int nums[12][maxn];
set<int> follow[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nums[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			follow[nums[i][j]].insert(nums[i][j+1]);
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << ": " << follow[i].size() << endl;
	// }

	ll ans = 0LL;
	ll grp = 0;
	for (int i = 0; i < n; i++) {
		int cur = nums[0][i];

		grp+=1LL;

		if (follow[cur].size() == 1) {
			continue;
		}
		else {
			ans += (grp)*(grp+1)/2LL;
			grp = 0LL;
		}

	}
	ans += (grp)*(grp+1)/2LL;
	cout << ans << endl;
}