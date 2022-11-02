#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector < int > a(n);
	vector < int > b(m);

	multiset < int > S;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		--a[i];
		S.insert(a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a.begin(), a.end());

	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		multiset < int > ::iterator it = S.lower_bound(i);
		if (it == S.end()) {
			break;
		}
		++cnt;
		S.erase(it);
	}
	
	vector < long long > sa(n);
	for (int i = 0; i < n; ++i) {
		sa[i] = b[a[i]];
		if (i > 0) {
			sa[i] += sa[i - 1];
		}
	}
	long long res = sa[n - 1], cur = 0;
	for (int i = n - 1, j = 0; i >= n - cnt; --i, ++j) {
		cur += b[j];
		res = min(res, cur + (i == 0 ? 0 : sa[i - 1]));
	}
	printf("%lld\n", res);
}

int main() {
    int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}