#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	ll totalRem = 0;
	vector<ll> cap(n, 0);
	for (int i = 0; i < n; ++i) {
		ll temp; cin >> temp;
		totalRem += temp;
	}
	for (int i = 0; i < n; ++i) {
		cin >> cap[i];
	}
	sort(cap.begin(), cap.end());

	if (cap[n-1] + cap[n-2] >= totalRem) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}