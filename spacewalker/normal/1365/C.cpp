#include <bits/stdc++.h>

using namespace std;

vector<int> placeIn(vector<int> x) {
	vector<int> ans(x.size());
	for (int i = 0; i < x.size(); ++i) {
		ans[x[i]] = i;
	}
	return ans;
}

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	for (int i = 0; i < n; ++i) --a[i], --b[i];
	vector<int> shct(n);
	vector<int> pia = placeIn(a), pib = placeIn(b);
	for (int i = 0; i < n; ++i) ++shct[(pib[i] - pia[i] + n) % n];
	printf("%d\n", *max_element(begin(shct), end(shct)));
	return 0;
}