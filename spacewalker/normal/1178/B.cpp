#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 1000010;

char str[NMAX];
int cvb[NMAX], cva[NMAX];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 1; i < n; ++i) {
		cvb[i] = cvb[i-1] + (str[i] == 'v' && str[i-1] == 'v' ? 1 : 0);
	}
	for (int i = n - 2; i >= 0; --i) {
		cva[i] = cva[i + 1] + (str[i] == 'v' && str[i+1] == 'v' ? 1 : 0);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'o') {
			ans += (ll)cvb[i] * cva[i];
		}
	}
	printf("%lld\n", ans);		 
	return 0;
}