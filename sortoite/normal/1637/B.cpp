#include<bits/stdc++.h>
using namespace std;
const int N = 111;
int a[N];
map<int, int> tmp;
int get_mex(int L, int R) {
	tmp.clear();
	for(int i = L; i <= R; i ++) {
		tmp[a[i]] = 1;
	}
	for(int i = 0; ; i ++) {
		if(!tmp.count(i)) {
			return i;
		}
	}
}
int b[N][N];
int solve() {
	int n; scanf("%d", &n);
	int ans = 0;
	memset(b, 0, sizeof b);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			b[i][j] = get_mex(i, j) + 1;
		}
	}
	for(int l = 2; l <= n; l ++) {
		for(int i = 1; i <= n - l + 1; i ++) {
			for(int k = i; k < i + l - 1; k ++) {
				b[i][i + l - 1] = max(b[i][i + l - 1], b[i][k] + b[k + 1][i + l - 1]);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			ans += b[i][j];
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
		printf("%d\n", solve());
	}
	return 0;
}