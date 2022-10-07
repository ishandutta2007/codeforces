#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	ans += ceil(2.0 * n / k);
	ans += ceil(5.0 * n / k);
	ans += ceil(8.0 * n / k);
	cout << ans << endl;
	return 0;
}