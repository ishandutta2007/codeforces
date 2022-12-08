#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll nums[100010];

int main() {
	ll tsum = 0LL;
	int N, p;
	cin >> N >> p;

	ll ans = 0LL;
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		tsum += nums[i];
	}
	int csum = 0LL;
	for (int i = 1;  i <= N-1; i++) {
		csum += nums[i];
		ans = max(ans, csum%p + (tsum-csum)%p);
	}
	cout << ans << endl;
	cin >> p;
}