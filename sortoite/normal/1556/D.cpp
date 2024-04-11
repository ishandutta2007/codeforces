#include <bits/stdc++.h>
using namespace std;

const int NN = 1e4 + 10;
int ans[NN], X[3][3], Y[3][3];
int a[] = {0, 1, 6, 4, 2, 3, 5, 4};

int A(int x, int y) {
//	return a[x] & a[y];
	cout << "and " << x << ' ' << y << endl;
	int res; cin >> res;
	return res;
}
int O(int x, int y) {
//	return a[x] | a[y];
	cout << "or " << x << ' ' << y << endl;
	int res; cin >> res;
	return res;
}

void pre(int u) {
	for(int x = 0; x <= 1; x ++) for(int y = 0; y <= 1; y ++) for(int z = 0; z <= 1; z ++) {
		if((x & y) == ((X[1][2] >> u) & 1)) 
		if((x | y) == ((Y[1][2] >> u) & 1)) 
		if((x & z) == ((X[1][3] >> u) & 1)) 
		if((x | z) == ((Y[1][3] >> u) & 1)) 
		if((z & y) == ((X[3][2] >> u) & 1)) 
		if((z | y) == ((Y[3][2] >> u) & 1)) {
			if(x) ans[1] |= (1 << u);
			if(y) ans[2] |= (1 << u);
			if(z) ans[3] |= (1 << u);
			return;
		}
	}
}

int main() {
	int n, k; cin >> n >> k;
	for(int i = 1; i <= 3; i ++) {
		for(int j = i + 1; j <= 3; j ++) {
			X[i][j] = X[j][i] = A(i, j);
			Y[i][j] = Y[j][i] = O(i, j);
		}
	}
	for(int i = 31; i--; pre(i));
	for(int i = 4; i <= n; i ++) {
		int x = A(1, i), y = O(1, i);
		for(int j = 0; j <= 30; j ++) {
			int z = (ans[1] >> j) & 1;
			if(((x >> j) & 1) != 0 || ((y >> j) & 1) != z) {
				ans[i] |= (1 << j);
			}
		}
	}
	sort(ans + 1, ans + n + 1);
	cout << "finish " << ans[k] << endl;
	return 0;
}