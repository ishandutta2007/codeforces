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

void solve() {
	int x, n;
	scanf("%d", &n);
	ll sum = 0;
	int maxNeg = -INF;
	int minPos = INF;

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += abs(x);
		if (x >= 0) minPos = min(x, minPos);
		if (x <= 0) maxNeg = max(x, maxNeg);
	}

	if (n == 1) {
		cout << x << "\n";
	} else {
		if (maxNeg == -INF) sum -= minPos * 2;
		if (minPos == INF) sum += maxNeg * 2;

		cout << sum << "\n";
	}
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}