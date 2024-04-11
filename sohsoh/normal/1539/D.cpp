// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
vector<pll> v;
deque<pll> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({b, a});
	}

	sort(all(v));
	for (pll e : v) dq.push_back(e);

	ll t = 0, ans = 0;
	while (!dq.empty()) {
		ll req = dq.front().X;
		while (t < req && !dq.empty()) {
			ll p = min(dq.back().Y, req - t);
			dq.back().Y -= p;
			ans += 2 * p;
			if (dq.back().Y == 0) dq.pop_back();
			t += p;
		}
	
		if (dq.empty()) continue;
		ans += dq.front().Y;
		t += dq.front().Y;
		dq.pop_front();
	}

	cout << ans << endl;
	return 0;
}