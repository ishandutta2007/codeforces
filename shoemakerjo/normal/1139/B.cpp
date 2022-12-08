#include <bits/stdc++.h>

using namespace std;

int n;
using ll = long long;

const int maxn = 200010;

ll nums[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	ll res = 0LL;
	for (int i = n-1; i >= 1; i--) {
		nums[i] = min(nums[i], max(0LL, nums[i+1]-1LL));

	}
	for (int i = 1; i <= n; i++) {
		res += nums[i];
	}
	cout << res << endl;
}