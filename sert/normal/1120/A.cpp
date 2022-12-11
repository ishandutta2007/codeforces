#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vector<int> cnt(N, 0);
	vector<int> a(m), b(s);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int numNeg = 0;
	for (int i = 0; i < s; i++) {
		cin >> b[i];
		if (cnt[b[i]] == 0) {
			numNeg++;
		}
		cnt[b[i]]--;		
	}

	int len = m - k * n + k;
	for (int i = 0; i < m; i++) {
		cnt[a[i]]++;
		if (cnt[a[i]] == 0) numNeg--;

		if (i >= len) {
			if (cnt[a[i - len]] == 0) numNeg++;
			cnt[a[i - len]]--;
		}

		if (i + 1 >= len && numNeg == 0 && i % k == (len - 1) % k) {
			vector<int> ans;
			vector<int> c(N, 0);
			for (int x: b) c[x]--;
			for (int j = i - len + 1; j <= i; j++) {				
				c[a[j]]++;
				if (c[a[j]] > 0 && (int)ans.size() < m - k * n) {
					ans.push_back(j + 1);
				}
			}
			cout << ans.size() << "\n";
			for (int x: ans) cout << x << " ";
			cout << "\n";
			return;
		}
	}

	cout << "-1\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 4;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}