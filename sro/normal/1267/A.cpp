#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 18;
const ll linf = 1e18;
int n;
ll L[N], R[N], T[N];
set <pair <ll, int> > before, after, beginning;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		scanf("%lld %lld %lld", &L[i], &R[i], &T[i]);
		before.insert(make_pair(L[i] + T[i], i));
		beginning.insert(make_pair(L[i], i));
	}
	vector <pair <ll, int> > event;
	for (int i = 0; i < n; ++ i) {
		event.push_back(make_pair(L[i], i));
		event.push_back(make_pair(R[i] - T[i] + 1, i + N));
	}
	sort(event.begin(), event.end());
	int i = 0;
	ll t = 0, ans = 0;
	while (t <= linf && i < event.size()) {
		ll mn = linf; int mnid;
		if (!before.empty() && before.begin() -> first < mn) mn = before.begin() -> first, mnid = before.begin() -> second;
		if (!after.empty() && after.begin() -> first + t < mn) mn = after.begin() -> first + t, mnid = after.begin() -> second;
		if (mn == linf) break;
		ll nex = max(L[mnid], t);
		auto it = beginning.upper_bound(make_pair(nex, 1e9));
		ll stp = min(R[mnid], it == beginning.end() ? linf : it -> first);
		ll cur = max(1LL, (stp - nex) / T[mnid]);
		ans += cur; t = nex + cur * T[mnid];
		while (i < event.size() && event[i].first <= t) {
			int id = event[i].second;
			if (id < N) before.erase(make_pair(L[id] + T[id], id)), after.insert(make_pair(T[id], id));
			else after.erase(make_pair(T[id - N], id - N));
			++ i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}