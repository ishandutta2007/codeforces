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

int a[N];
int b[N];

void solve() {
	int n;
	vector<int> ans;
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i - 1] = a[i] - a[i - 1];
	}

	for (int k = 1; k <= n; k++) {
		bool ok = true;
		for (int i = k; i < n; i++) {
			if (b[i] != b[i - k]) ok = false;
		}
		if (ok) ans.push_back(k);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
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