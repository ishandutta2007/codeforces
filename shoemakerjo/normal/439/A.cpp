#include <iostream>

using namespace std;

int main() {
	int n,d;
	cin >> n >> d;
	int sum = 0;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		sum+=cur;
	}
	if (sum + 10*(n-1) > d) {
		cout << -1 << "\n";
	}
	else {
		int ans = (d-sum)/5;
		cout << ans << "\n";
	}
	// cin >> n;
}