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

int getSum(int x) {
	return (x < 10 ? x : x % 10 + getSum(x / 10));
}

void solve() {
	vector<int> a;
	for (int i = 19; a.size() <= 10000; i++) {
		if (getSum(i) == 10) {
			a.push_back(i);
		}
	}
	int x;
	cin >> x;
	cout << a[x - 1] << "\n";
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