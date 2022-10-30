#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long solve(long long n) {
	if (n >= 11) return 49 * n - 247;
	vector<int> v;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; i + j <= n; ++j) {
			for (int k = 0; i + j + k <= n; ++k) {
				int l = n - i - j - k;
				v.push_back(i + 5 * j + 10 * k + 50 * l);
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v.size();
}
int main() {
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}