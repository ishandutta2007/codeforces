#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += i*(n+1-i);
		ans -= (i-1);
	}

	cout << ans << '\n';
}