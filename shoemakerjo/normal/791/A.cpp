#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ans = 0;
	while (a <= b) {
		a*=3;
		b*=2;
		ans++;
	}
	cout << ans << endl;
	// cin >> a;
}