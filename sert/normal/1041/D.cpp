#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
//const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

ll len[N], gap[N];
int x1[N], x2[N];

void solve() {
	int n, hh;
	scanf("%d%d", &n, &hh);
	ll h = hh;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", x1 + i, x2 + i);
	}
	for (int i = 0; i < n; i++) {
		len[i] = x2[i] - x1[i];
		gap[i] = (i + 1 == n ? INF : x1[i + 1] - x2[i]);
	}

	ll curh = h;
	ll curx = x2[0];
	int cur = 0;
	ll ans = 0;
	for (int st = 0; st < n; st++) {
		if (st > 0) {
			curh += gap[st - 1];			
		}

		while (curh > gap[cur]) {
			curh -= gap[cur];
			curx += gap[cur] + len[cur + 1];
			cur++;
		}

		//cout << curx << " " << curh << " " << st << "\n";

		ans = max(ans, curx + curh - x1[st]);
	}

	cout << ans << "\n";
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