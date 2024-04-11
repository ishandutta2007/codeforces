#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		vector<int> odd, even;
		scanf("%d", &n);
		for (int i = 1; i <=2 * n; i ++) {
			int x; scanf("%d", &x);
			if (x % 2 == 1) odd.push_back(i); else even.push_back(i);
		}
		if (odd.size() % 2) odd.pop_back();
		if (even.size() % 2) even.pop_back();
		vector<int> ans;
		for (auto x: odd) ans.push_back(x);
		for (auto x: even) ans.push_back(x);
		for (int i = 0; i < 2 * (n - 1); i ++) printf("%d ", ans[i]);
		printf("\n");
	}
}