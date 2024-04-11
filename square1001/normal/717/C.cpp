#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 10007;
int n, a[100009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = (ret + 1LL * a[i] * a[n - i - 1]) % mod;
	}
	cout << ret << endl;
	return 0;
}