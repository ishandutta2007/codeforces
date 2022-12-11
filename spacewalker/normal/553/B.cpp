#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 60;
ll permcts[NMAX];

int main() {
	int n; ll k; scanf("%d %lld", &n, &k);
	permcts[0] = 1;
	permcts[1] = 1;
	permcts[2] = 2;
	for (int i = 3; i < NMAX; ++i) permcts[i] = permcts[i-1] + permcts[i-2];

	vector<int> ans(n);
	for (int i = 0; i < n;) {
		if (permcts[n-i-1] >= k) {
			ans[i] = i;
			++i;
		} else {
			k -= permcts[n-i-1];
			ans[i] = i + 1, ans[i + 1] = i;
			i += 2;
		}
	}

	for (int k : ans) printf("%d ", k + 1);
	printf("\n");
	return 0;
}