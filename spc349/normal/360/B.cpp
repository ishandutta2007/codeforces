#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;

int n, k;
int a[200010];
vector <pll> all;
vector <long long> seq;

bool check(long long mid) {
	all.clear();
	for (int i = 0; i < n; i++) {
		all.push_back(mp(i * mid - a[i], i * mid + a[i]));
	}
	sort(all.begin(), all.end()), seq.clear();
	for (int i = 0; i < n; i++) {
		vector <long long> :: iterator it = upper_bound(seq.begin(), seq.end(), all[i].se);
		if (it == seq.end()) seq.push_back(all[i].se);
		else *it = all[i].se;
		if (seq.size() >= n - k) return 1;
		if (seq.size() + n - i - 1 < n - k) return 0;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long l = 0, r = 2000000000;
	while (l < r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}