#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
ll a[110];
ll k;

set<ll> s;

int main() {
	cin >> n >> k;

	rep(i, n) {
		cin >> a[i];
		for (int j = 1; j * j <= a[i]; ++j) {
			int x = a[i] / j;
			s.insert(x-1);
			s.insert(x);
			s.insert(x+1);
		}
	}

	for (int i = 1; i * i <= 1e9; ++i) {
		s.insert(i);
	}

	s.insert(*max_element(a, a + n) + k / n + 1);

	ll ans = -1;

	ll K = k;
	rep(i, n) K += a[i];

	for (auto it = s.begin(); it != s.end(); ++it) {
		auto it2 = it; ++it2; if (it2 == s.end()) break;

		ll lo = *it, hi = *it2;
		if (lo <= 0) continue;

		ll sm = 0;
		rep(i, n) sm += (a[i] + lo - 1) / lo;
		if (lo * sm > K) continue;
		ans = max(ans, min(hi - 1, K / sm));
	}

	cout << ans << endl;

	return 0;
}