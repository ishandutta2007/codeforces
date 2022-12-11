#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define accum(v, T1, T2, f) accumulate(all(v), 0, [&](T1 sum, T2 x) {return f;})
#define accum_ii(v, f) accumulate(all(v), 0, [&](int sum, int x) {return f;})
#define accum_ll(v, f) accumulate(all(v), 0, [&](ll sum, ll x) {return f;})
#define read(v) for (auto &x : v) cin >> x;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	read(a);
	int odd = accum_ii(a, sum + x % 2);
	cout << min(odd, n - odd) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
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