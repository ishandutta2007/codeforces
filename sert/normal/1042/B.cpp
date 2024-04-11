#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (1 << 3);
const int M = (1 << N);
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

int a[N];
int dp[N];

void solve() {
	for (int i = 0; i < N; i++) {
		a[i] = INF;
	}
	for (int i = 0; i < N; i++) {
		dp[i] = INF;
	}
	dp[0] = 0;

	int n;
	cin >> n;
	while (n--) {
		int x;
		string s;
		cin >> x >> s;
		int msk = 0;
		for (char ch: s) {
			msk |= (1 << (ch - 'A'));
		}
		a[msk] = min(a[msk], x);
	}

	for (int msk = 0; msk < N; msk++) {
		for (int sok = 0; sok < N; sok++) {
			dp[msk | sok] = min(dp[msk | sok], dp[msk] + a[sok]);
		}
	}

	cout << (dp[N - 1] == INF ? -1 : dp[N - 1]) << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 5;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}