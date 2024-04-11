#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e4 + 7;
const int M = 103;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
bool D = false;

ll MD = 1000000000;

bool isPrime(ll x) {
	for (ll q = 2; q * q <= x; q++) {
		if (x % q == 0) return false;
	}
	return true;
}

ll c[111][111];
void init() {
	MD += rand() % 100000;
	while (!isPrime(MD)) MD++;

	c[0][0] = 1;
	for (int i = 1; i <= 104; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			c[i][j] %= MD;
		}
	}
}

int dp[N][M];

void solve() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) dp[i][j] = 0;
	int n;
	cin >> n;	
	dp[0][0] = 1;
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
		for (int j = N - a[i] - 1; j >= 0; j--) {
			for (int k = 0; k <= i; k++) {
				dp[j + a[i]][k + 1] += dp[j][k];
				dp[j + a[i]][k + 1] %= MD;			
			}
		} 
	}

	if ((int)m.size() <= 2) {
		cout << n << "\n";
		return;
	}

	int ans = 1;
	for (int i = 0; i < N; i++) {
		for (auto it: m) {
			int val = it.first;
			int num = it.second;			

			if (i % val) continue;
			int cur = i / val;

			if (cur <= num && dp[i][cur] == c[num][cur]) {
				ans = max(ans, cur);
			}
		}
	}

	cout << ans << "\n";
}

int main() {
	srand(time(NULL));
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}