#include <bits/stdc++.h>
using namespace std;

int q[12][3][1011];
int ans[1011];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	memset(q, 0x3f, sizeof(q));
	for(int t = 0; t < 2; t ++)
		for(int i = 0; i < 10; i ++) {
			vector <int> v;
			for(int j = 0; j < n; j ++)
				if(((j >> i) & 1) == t) {
					v.push_back(j + 1);
				}
			if(v.size()) {
				cout << v.size() << '\n';
				for(int x : v) cout << x << ' ';
				cout << '\n';
				fflush(stdout);
				for(int j = 0; j < n; j ++)
					cin >> q[i][t][j];
			}
		}
	for(int i = 0; i < n; i ++) {
		ans[i] = 1e9L;
		for(int j = 0; j < 10; j ++)
			for(int t = 0; t < 2; t ++)
				if(((i >> j) & 1) != t)
					ans[i] = min(ans[i], q[j][t][i]);
	}
	cout << -1 << '\n';
	for(int i = 0; i < n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
	fflush(stdout);
	return 0;
}