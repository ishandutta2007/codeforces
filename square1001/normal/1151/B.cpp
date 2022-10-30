#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<vector<int> > A(H, vector<int>(W));
	int cur = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> A[i][j];
		}
		cur ^= A[i][0];
	}
	int px = -1, py = -1;
	for (int i = 0; i < H && px == -1; ++i) {
		for (int j = 0; j < W; ++j) {
			int nxt = cur ^ A[i][0] ^ A[i][j];
			if (nxt > 0) {
				px = i, py = j;
				break;
			}
		}
	}
	if (px >= 0 && py >= 0) {
		cout << "TAK" << endl;
		for (int i = 0; i < H; ++i) {
			if (i) cout << ' ';
			cout << (i == px ? py + 1 : 1);
		}
		cout << endl;
	}
	else {
		cout << "NIE" << endl;
	}
	return 0;
}