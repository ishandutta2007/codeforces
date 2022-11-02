#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int H, G;
		cin >> H >> G;
		vector<int> A(1 << H);
		for (int i = 1; i < 1 << H; ++i) {
			cin >> A[i];
		}
		vector<pair<int, int> > submin(2 << H, make_pair(1 << 30, -1));
		for (int i = (1 << H) - 1; i >= 1; --i) {
			submin[i] = min(submin[i], make_pair(A[i], i));
			submin[i >> 1] = min(submin[i >> 1], submin[i]);
		}
		vector<bool> remain(1 << H, false), drop(1 << H, false);
		vector<int> limit(1 << H, -1);
		long long ans = 0;
		for (int i = G - 1; i >= 0; --i) {
			for (int j = 1 << i; j < 2 << i; ++j) {
				while (true) {
					int pos = submin[j].second, ppos = pos, val = submin[j].first;
					submin[pos] = make_pair(1 << 30, -1);
					drop[pos] = true;
					while (pos >= 1) {
						submin[pos] = min({ !drop[pos] ? make_pair(A[pos], pos) : make_pair(1 << 30, -1), submin[pos * 2], submin[pos * 2 + 1] });
						pos >>= 1;
					}
					if (val >= limit[j]) {
						limit[j / 2] = max(limit[j / 2], val);
						remain[ppos] = true;
						ans += val;
						break;
					}
				}
			}
		}
		cout << ans << '\n';
		int cnt = 0;
		for (int i = (1 << H) - 1; i >= 1; --i) {
			if (!remain[i]) {
				if (cnt++) cout << ' ';
				cout << i;
			}
		}
		cout << '\n';
	}
	return 0;
}