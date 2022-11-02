#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	int x = s[0] - 'a';
	int y = s[1] - '1';
	int ret = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int tx = x + dx, ty = y + dy;
			if (0 <= tx && tx <= 7 && 0 <= ty && ty <= 7) {
				ret++;
			}
		}
	}
	cout << ret - 1 << endl;
	return 0;
}