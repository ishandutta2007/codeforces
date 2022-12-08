#include <iostream>

using namespace std;

int main() {
	bool ok = true;
	int cur25 = 0;
	int cur50 = 0;
	int cur100 = 0;
	int cost;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cost;
		if (cost == 100) {
			if (cur50 > 0 && cur25 > 0) {
				cur50--;
				cur25--;
				cur100++;
			}
			else if (cur25 >= 3) {
				cur25-=3;
				cur100++;
			}
			else ok = false;
		}
		if (cost == 50) {
			if (cur25 > 0) {
				cur25--;
			}
			else ok = false;
			cur50++;
		}
		if (cost == 25) cur25++;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> n;

}