#include <iostream>
using namespace std;
int p[4][4];
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) cin >> p[i][j];
	}
	bool ret = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (p[i][j] == 1 && p[i][3] == 1) ret = true;
			if (p[i][j] == 1 && p[(i + 3 - j) & 3][3] == 1) ret = true;
		}
	}
	cout << (ret ? "YES" : "NO") << endl;
	return 0;
}