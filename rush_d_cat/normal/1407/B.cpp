#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
int gcd(int x, int y) {
	return y == 0 ? x: gcd(y, x % y);
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		vector<int> ans, v;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]); v.push_back(a[i]);
		}
		int g = 0;
		while (v.size()) {
			int mx = 0, bst = 0;
			if (g == 0) {
				for (auto x: v) {
					if (x > mx) {
						mx = x; bst = x;
					}
				}
			} else {
				for (auto x: v) {
					if (gcd(x, g) > mx) {
						mx = gcd(x, g); bst = x;
					}
				}
			}

			vector<int> nex;
			for (auto x: v) {
				if (x == bst) {
					ans.push_back(x);
				} else {
					nex.push_back(x);
				}
			}
			v = nex; g = mx;
		}
		for (auto x: ans) {
			printf("%d ", x);
		}
		printf("\n");

	}

}