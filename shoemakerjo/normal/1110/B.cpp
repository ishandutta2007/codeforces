#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int n, m, k;

int nums[maxn];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		if (i - 1) {
			pq.push(nums[i] - nums[i-1] - 1);
		}
	}
	int ans = n;
	for (int i = 0; i < n-k; i++) {
		ans += pq.top(); pq.pop();
	}
	cout << ans << endl;
}