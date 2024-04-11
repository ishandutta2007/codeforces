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

int n;
int a[N], b[N];

bool go() {
	vector<int> ans(n + 2);
	ans[0] = 0;
	ans[1] = a[0];
	ans[2] = b[0];

	for (int i = 1; i < n; i++) {
		int v = ans[i];		
		if (ans[i + 1] == a[v]) ans[i + 2] = b[v];
		else if (ans[i + 1] == b[v]) ans[i + 2] = a[v];
		else return false;
	}

	if (ans[0] != ans[n] || ans[1] != ans[n + 1]) return false;

	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}	

	if (go()) return;
	swap(a[0], b[0]);
	go();
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
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}