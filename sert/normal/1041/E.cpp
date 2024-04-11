#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

int a[N];
bool u[N];

void solve() {
	int n;
	scanf("%d", &n);
	bool fail = false;
	for (int i = 0; i < n; i++) u[i] = false;

	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		if (v1 == v2 || max(v1, v2) != n) fail = true;
		a[i] = min(v1, v2) - 1;
		u[a[i]] = true;
	}

	a[n - 1] = n - 1;
	sort(a, a + n);
	reverse(a, a + n);

	u[n - 1] = true;
	int cur = n - 1;

	for (int i = 0; i + 1 < n; i++) {
		if (a[i] == a[i + 1]) {
			while (u[cur]) cur--;
			if (cur < a[i]) a[i] = cur--;
			else fail = true;
		}
	}

	if (fail) {
		printf("NO\n");
		return;
	} 
	printf("YES\n");

	for (int i = 0; i < n - 1; i++) {
		printf("%d %d\n", a[i] + 1, a[i + 1] + 1);
	}
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}