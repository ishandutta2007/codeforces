#include <bits/stdc++.h>

using namespace std;
#define maxn 1010
int n;
int nums[maxn];
int diffs[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	nums[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i <= n; i++) {
		diffs[i] = nums[i] - nums[i-1];
	}

	vector<int> ans;
	for (int k = 1; k <= n; k++) {
		bool ok = true;
		for (int i = k+1; i <= n; i++) {
			if (diffs[i] != diffs[i-k]) ok = false;
		}
		if (ok) ans.push_back(k);
	}
	cout << ans.size() << endl;
	for (int vv : ans) cout << vv << " ";
		cout << endl;

}