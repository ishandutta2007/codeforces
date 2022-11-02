#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 19999999;
int cost(vector<int> v) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i != v[i]) cnt++;
	}
	if (cnt <= 2) return cnt >> 1;
	return inf;
}
int H, W;
int main() {
	cin >> H >> W;
	vector<vector<int> > a(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j]; a[i][j]--;
		}
	}
	int ret = inf;
	for (int i = 0; i < W; i++) {
		for (int j = i; j < W; j++) {
			int res = 0;
			for (int k = 0; k < H; k++) {
				vector<int> b = a[k];
				swap(b[i], b[j]);
				res += cost(b);
			}
			ret = min(ret, res);
		}
	}
	cout << (ret <= H + 1 ? "YES" : "NO") << endl;
	return 0;
}