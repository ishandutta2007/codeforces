#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, m, k; scanf("%lld %lld %lld", &n, &m, &k);
	vector<ll> specials(m);
	for (int i = 0; i < m; ++i) scanf("%lld", &specials[i]);
	ll pageStart = 1;
	// page is from pageStart to pageStart + k - 1
	ll cNonRem = 0;
	int ans = 0;
	while (cNonRem < m) {
		ll nextR = specials[cNonRem];
		if (nextR >= pageStart + k) {
			// move pageStart
			ll pagesToMove = (nextR - pageStart) / k;
			pageStart += pagesToMove * k;
		} else {
			// delete pages
			int firstStayPage = cNonRem;
			while (firstStayPage < m && specials[firstStayPage] < pageStart + k) ++firstStayPage;
			int pagesToDel = firstStayPage - cNonRem;
			pageStart += pagesToDel;
			cNonRem = firstStayPage;
			++ans;
		}
	}	
	printf("%d\n", ans);
	return 0;
}