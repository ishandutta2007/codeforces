#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	vector<int> c(n);
	multiset<int> curB;
	for (int x : b) curB.insert(x);
	for (int i = 0; i < n; ++i) {
		// as much as possible, want the min val >= n - a[i]
		// if impossible, just take minimal value
		auto pTakeIter = curB.lower_bound((n - a[i]) % n);
		if (pTakeIter == curB.end()) {
			pTakeIter = curB.begin();
		}
		c[i] = (a[i] + *pTakeIter) % n;
		curB.erase(pTakeIter);
	}
	for (int x : c) printf("%d ", x);
	printf("\n");
	return 0;
}