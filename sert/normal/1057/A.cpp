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
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	n--;
	vector<int> kk = {n};
	while (n != 0) {
		n = a[n];
		kk.push_back(n);
	}
	for (int i = (int)kk.size() - 1; i >= 0; i--) {
		cout << kk[i] + 1 << " ";
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
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}