#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = -2000000000;
	int f, t;
	for (int i = 0;i < n; i++) {
		cin >> f >> t;
		ans = max(ans, min(f, f-t+k));
	}
	cout << ans << endl;
	// cin >> n;
}