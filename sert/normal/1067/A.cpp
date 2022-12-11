#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e5 + 34;
const int M = 200;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = 998244353;
bool D = false;

ll dp0[N][M + 2];
ll dpI[N][M + 2];
ll dpD[N][M + 2];

vector<int> v;
int stress(vector<int> a, int len = 0) {
	if (len == (int)a.size()) {
		if (a[0] > a[1] || a[len - 2] < a[len - 1]) return 0;
		for (int i = 1; i + 1 < len; i++) {
			if (a[i] > max(a[i - 1], a[i + 1])) return 0;
		}
		return 1;
	}
	if (a[len] != -1) return stress(a, len + 1);
	int ans = 0;
	for (int j = 1; j <= M; j++) {
		a[len] = j;
		ans = (ans + stress(a, len + 1)) % MD;
	}
	a[len] = -1;
	return ans;
}

int solve(bool dd = false) {
	int n;
	if (dd) n = v.size();
	else cin >> n;
	dp0[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		if (dd) x = v[i - 1];
		else cin >> x;

		if (x == -1) {
			for (int j = 1; j <= M; j++) {
				dp0[i][j] = (dp0[i - 1][j] + dpI[i - 1][j] + dpD[i - 1][j]) % MD;
			}
			ll cur = 0;
			for (int j = 1; j <= M; j++) {
				cur = (cur + dpI[i - 1][j - 1] + dp0[i - 1][j - 1] + dpD[i - 1][j - 1]) % MD;
				dpI[i][j] = cur;
			}
			cur = 0;
			for (int j = M; j >= 1; j--) {
				cur = (cur + dpD[i - 1][j + 1] + dp0[i - 1][j + 1]) % MD;
				dpD[i][j] = cur;
			}
		} else {
			for (int j = 0; j <= M; j++) dp0[i][j] = dpI[i][j] = dpD[i][j] = 0;
			dp0[i][x] = (dp0[i - 1][x] + dpI[i - 1][x] + dpD[i - 1][x]) % MD;
			ll dpi = 0, dpd = 0;
			for (int j = 0; j < x; j++) dpi = (dpi + dpI[i - 1][j] + dpD[i - 1][j] + dp0[i - 1][j]) % MD;
			for (int j = x + 1; j <= M; j++) dpd = (dpd + dpD[i - 1][j] + dp0[i - 1][j]) % MD;
			dpI[i][x] = dpi;
			dpD[i][x] = dpd;
		}
	}

	int ans = 0;
	for (int j = 1; j <= M; j++) {
		ans = (ans + dp0[n][j] + dpD[n][j]) % MD;
	}

	return ans;
}

void check() {
	int it = 0;
	while (clock() < CLOCKS_PER_SEC * 3.4) {
		it++;
		v = {-1, -1, -1, -1, rand() % M + 1, rand() % M + 1, rand() % M + 1};
		random_shuffle(v.begin(), v.end());
		int s1 = solve(true);
		int s2 = stress(v);
		if (s1 != s2) {
			cout << s1 << " " << s2 << " at it = " << it << "\n";
			for (int i = 0; i < (int)v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
			return;
		}
	}
}

int main() {
	srand(3431);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	cout << solve() << "\n";
	//cout << stress({20, -1, -1, -1, 20}) << "\n";
	//check();
#else
	cout << solve() << "\n";
#endif
}