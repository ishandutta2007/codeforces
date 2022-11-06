#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, n1, n2;
	cin >> n >> n1 >> n2;
	vector<long long> data;
	data.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	reverse(data.begin(), data.end());
	long long sum = 0;
	double ans = 0;
	for (int i = 0; i < min(n1, n2); i++) {
		sum += data[i];
	}
	ans += (double)sum / min(n1, n2);
	sum = 0;
	for (int i = min(n1, n2); i < n1 + n2; i++) {
		sum += data[i];
	}
	ans += (double)sum / max(n1, n2);
	cout << fixed << setprecision(8) << ans;
	return 0;
}