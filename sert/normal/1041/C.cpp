#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)2e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}

pair<int, int> a[N];
int ans[N];

void solve() {
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a, a + n);

	int cur = 0;
	int mx = -INF;
	a[n] = make_pair(INF, n);
	for (int i = 0; i < n; i++) {
		while (a[cur].first - a[i].first <= d) cur++;
		mx = max(mx, cur - i);
	}

	printf("%d\n", mx);
	for (int i = 0; i < n; i++) {
		ans[a[i].second] = 1 + i % mx;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}