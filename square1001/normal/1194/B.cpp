#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1 << 30;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		int H, W;
		cin >> H >> W;
		vector<string> S(H);
		for(int i = 0; i < H; ++i) {
			cin >> S[i];
		}
		vector<int> nh(H), nw(W);
		for(int i = 0; i < H; ++i) {
			for(int j = 0; j < W; ++j) {
				if(S[i][j] == '.') {
					++nh[i];
					++nw[j];
				}
			}
		}
		int ans = inf;
		for(int i = 0; i < H; ++i) {
			for(int j = 0; j < W; ++j) {
				ans = min(ans, nh[i] + nw[j] - (S[i][j] == '.' ? 1 : 0));
			}
		}
		cout << ans << endl;
	}
	return 0;
}