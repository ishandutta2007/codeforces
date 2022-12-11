#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
vector <pii> op;
priority_queue <long long> L;
priority_queue <long long, vector <long long>, greater <long long> > R;
long long LL, RR;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		op.push_back(mp(x + y, x));
	}
	sort(op.begin(), op.end());
	for (int i = 0; i < n + 10; i++) L.push(0), R.push(0);
	int lst = 0; long long ans = 0;
	for (auto it : op) {
		int delta = it.fi - lst; RR += delta;
		if (it.se >= L.top() + LL && it.se <= R.top() + RR) L.push(it.se - LL), R.push(it.se - RR);
		else if (it.se < L.top() + LL) {
			L.push(it.se - LL), L.push(it.se - LL), R.push(L.top() + LL - RR), L.pop();
			ans += R.top() + RR - it.se;
		} else {
			R.push(it.se - RR), R.push(it.se - RR), L.push(R.top() + RR - LL), R.pop();
			ans += it.se - L.top() - LL;
		}
		lst = it.fi;
	}
	printf("%lld\n", ans);
	return 0;
}