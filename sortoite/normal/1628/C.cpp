#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int solve() {
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < n; j ++) {
			scanf("%d", a[i] + j);
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i += 4) {
		for(int x = 0, y = i; x < n && y < n; x += 2, y += 2) {
			ans ^= a[x][y];
			ans ^= a[y][n - 1 - x];
		}
	}
	for(int i = 3; i < n; i += 4) {
		for(int x = i, y = 0; x < n && y < n; x += 2, y += 2) {
			ans ^= a[x][y];
			ans ^= a[y][n - 1 - x];
		}
	}
	return ans;
}
	
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		cout << solve() << endl;
	}
	return 0;
}