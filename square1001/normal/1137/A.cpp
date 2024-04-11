#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<vector<int> > A(H, vector<int>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int> > low(H, vector<int>(W)), high(H, vector<int>(W));
	for (int i = 0; i < H; ++i) {
		vector<int> v = A[i];
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int j = 0; j < W; ++j) {
			int ptr = lower_bound(v.begin(), v.end(), A[i][j]) - v.begin();
			low[i][j] = max(low[i][j], ptr);
			high[i][j] = max(high[i][j], int(v.size()) - ptr - 1);
		}
	}
	for (int i = 0; i < W; ++i) {
		vector<int> v(H);
		for (int j = 0; j < H; ++j) {
			v[j] = A[j][i];
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int j = 0; j < H; ++j) {
			int ptr = lower_bound(v.begin(), v.end(), A[j][i]) - v.begin();
			low[j][i] = max(low[j][i], ptr);
			high[j][i] = max(high[j][i], int(v.size()) - ptr - 1);
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j) cout << ' ';
			cout << low[i][j] + high[i][j] + 1;
		}
		cout << '\n';
	}
	return 0;
}