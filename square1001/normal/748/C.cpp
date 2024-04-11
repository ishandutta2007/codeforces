#include <cmath>
#include <string>
#include <iostream>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	int px = 0, py = 0, ret = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int dx = 0, dy = 0;
		if (s[i] == 'L') dx = -1;
		if (s[i] == 'R') dx = 1;
		if (s[i] == 'U') dy = -1;
		if (s[i] == 'D') dy = 1;
		px += dx;
		py += dy;
		if (abs(px) + abs(py) != ++cnt) {
			cnt = 1;
			px = dx;
			py = dy;
			ret++;
		}
	}
	cout << ret + 1 << endl;
	return 0;
}