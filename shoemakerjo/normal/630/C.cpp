#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	ll cur = 2;
	for (int i = 1; i <= n; i++) {
		ans += cur;
		cur = cur*2;
	}
	cout << ans << endl;
	cin >> n;
}