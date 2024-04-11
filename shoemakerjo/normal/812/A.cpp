#include <iostream>

using namespace std;

int main() {
	int nums[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> nums[i][j];
		}
	}
	bool ok = true;
	
	for (int i = 0; i < 4; i++) {
		if (!nums[i][3]) continue;
		for (int j = 0; j < 3; j++) {
			if (nums[i][j]) ok = false;
		}
		for (int k = 1; k <= 3; k++) {
			if (nums[(i+k)%4][k-1]) ok = false;
		}
	}
	if (ok) cout << "NO" << endl;
	else cout << "YES" << endl;
	cin >> ok;
}