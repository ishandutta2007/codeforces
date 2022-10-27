#include <bits/stdc++.h>
using namespace std;
int main() {
	//ios::syn_with_stdio(false);
	//cout.tie(0);
	int t; scanf("%d", &t);
	while (t --) {
		int n; scanf("%d",&n);
		vector<int> a(n);
		for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
		sort(a.begin(), a.end());
		double ans = 0;
		for (int i = 0; i < n - 1; i ++) ans += 1.0 * a[i] / (n - 1);
		ans += a[n-1];
		printf("%.9f\n", ans);
	}
}