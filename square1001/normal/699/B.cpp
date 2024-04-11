#include <string>
#include <iostream>
using namespace std;
int H, W, a[1009], b[1009]; string s[1009];
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> s[i];
	int sum = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '*') a[i]++, b[j]++, sum++;
		}
	}
	bool flag = false;
	for (int i = 0; i < H && !flag; i++) {
		for (int j = 0; j < W && !flag; j++) {
			if (a[i] + b[j] - (s[i][j] == '*' ? 1 : 0) == sum) {
				cout << "YES" << endl;
				cout << i + 1 << ' ' << j + 1 << endl;
				flag = true;
			}
		}
	}
	if (!flag) cout << "NO" << endl;
	return 0;
}