#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> arr;
int m;

bool checkPossible(int days) {
	ll pages = 0;
	for (int i = 0; i < arr.size(); ++i) {
		pages += max(0LL, arr[i] - (i / days));
	}
//	printf("%lld pages possible on %d days\n", pages, days);
	return pages >= m;
}

int main() {
	int n; scanf("%d %d", &n, &m);
	arr = vector<ll>(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	sort(begin(arr), end(arr));
	reverse(begin(arr), end(arr));
	int lo = 1, hi = n;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (checkPossible(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (checkPossible(lo)) printf("%d\n", lo);
	else printf("-1\n");
	return 0;
}