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
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> d(n);
	for (int i = 1; i < n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	sort(d.rbegin(), d.rend());
	long long ans = a[n - 1] - a[0];
	for (int i = 0; i < k - 1; i++) {
		ans -= d[i];
	}
	cout << ans;
	return 0;
}