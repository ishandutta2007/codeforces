#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int n;
int nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	int mincost = 1e8;
	int val = -1;
	for (int t = 1; t <= 100; t++) {
		int cans = 0;
		for (int i = 1; i <= n; i++) {
			if (nums[i] < t-1) {
				cans += t-1-nums[i];
			}
			else if (nums[i] > t+1) {
				cans += nums[i]-t-1;
			}
		}
		if (cans < mincost) {
			mincost = cans;
			val = t;
		}
	}
	cout << val << " " << mincost << endl;
}