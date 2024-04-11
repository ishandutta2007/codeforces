#include <iostream>
using namespace std;
int n, t, k, d;
int main() {
	cin >> n >> t >> k >> d;
	int x = (n + k - 1) / k * t;
	if (x <= d) cout << "NO" << endl;
	else {
		int z = n - k + (x - d - 1) / t * k;
		cout << (z >= n ? "YES" : "NO") << endl;
	}
	return 0;
}