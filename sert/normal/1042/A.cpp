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
void solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	int mx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		mx = max(mx, a[i]);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (mx - a[i]);
	}

	printf("%d %d\n", mx + (k <= sum ? 0 : (k - sum + n - 1) / n), mx + k);
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 4;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}