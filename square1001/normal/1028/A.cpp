#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	int sx = 0, sy = 0, cnt = 0;
	for (int i = 0; i < H; ++i) {
		cin >> S[i];
		for (int j = 0; j < W; ++j) {
			if (S[i][j] == 'B') {
				++cnt;
				sx += i + 1;
				sy += j + 1;
			}
		}
	}
	cout << sx / cnt << ' ' << sy / cnt << endl;
	return 0;
}