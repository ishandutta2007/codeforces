#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	map<int, vector<int> > G;
	map<int, int> group;
	map<int, int> arr;
	int last = 0;
	for (int i = 0; i < Q; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int L, R, X;
			cin >> L >> R >> X;
			L ^= last;
			R ^= last;
			X ^= last;
			if (L > R) swap(L, R);
			++R;
			int gl = L + group[L], gr = R + group[R];
			if (gl == gr) continue;
			int sl = max(int(G[gl].size()), 1);
			int sr = max(int(G[gr].size()), 1);
			if (sl < sr) {
				swap(L, R);
				swap(gl, gr);
				swap(sl, sr);
			}
			if (sl == 1) G[gl].push_back(L);
			if (sr == 1) G[gr].push_back(R);
			X ^= arr[L] ^ arr[R] ^ arr[gl] ^ arr[gr];
			for (int j : G[gr]) arr[j] ^= X, group[j] -= gr - gl;
			G[gl].insert(G[gl].end(), G[gr].begin(), G[gr].end());
			G[gr].clear();
		}
		else {
			int L, R;
			cin >> L >> R;
			L ^= last;
			R ^= last;
			if (L > R) swap(L, R);
			++R;
			if (group[L] + L == group[R] + R) {
				int ans = arr[L] ^ arr[R];
				last = ans;
				cout << ans << '\n';
			}
			else {
				last = 1;
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}