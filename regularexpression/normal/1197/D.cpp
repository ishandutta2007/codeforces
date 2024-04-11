#include<algorithm>
#include<iostream>
#include<numeric>
#include<iomanip>
#include<cassert>
#include<chrono>
#include<string>
#include<vector>
#include<random>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<set>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	long long k;
	cin >> n >> m >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> sum(n, 0);
	for (int i = m - 1; i < n; i++) {
		sum[i] = 0;
		for (int j = 0; j < m; j++) {
			sum[i] += a[i - j];
		}
		sum[i] -= k;
	}
	vector<long long> max_sum(n, 0);
	if (m <= n) {
		max_sum[m - 1] = max(max_sum[m - 1], sum[m - 1]);
	}
	for (int i = m; i < n; i++) {
		max_sum[i] = max(max_sum[i], max_sum[i - m] + sum[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, max_sum[i]);
		long long delta = 0;
		for (int j = i + 1; j < min(i + m, n); j++) {
			delta += a[j];
			ans = max(ans, max_sum[i] + delta - k);
		}
	}
	long long delta = 0;
	for (int i = 0; i < n; i++) {
		delta += a[i];
		ans = max(ans, delta - k * ((i + 1 + m - 1) / m));
	}
	cout << ans;
	return 0;
}