#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	int i1, in;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) i1 = i;
		if (a[i] == n) in = i;
	}
	int ans = 0;
	ans = max(ans, i1);
	ans = max(ans, in);
	ans = max(ans, n-i1-1);
	ans = max(ans, n-in-1);
	cout << ans << endl;
	// cin >> n;
}