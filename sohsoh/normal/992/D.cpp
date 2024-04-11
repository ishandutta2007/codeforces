#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll OVF = ll(6e18) + 10;

vector<int> vec;
int n, k, A[MAXN];

inline ll ovf_mul(ll a, ll b) {
	if (a > OVF / b) return OVF;
	return a * b;
}

inline ll C2(ll n) {
	return n - 1;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> k;

	vec.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (A[i] > 1) vec.push_back(i);
	}
	
	vec.push_back(n + 1);
	
	ll ans = 0;
	for (int i = 1; i < int(vec.size()) - 1; i++) {
		ll p = 1, s = 0;

		for (int j = i; j < int(vec.size()) - 1; j++) {
			p = ovf_mul(A[vec[j]], p);
			if (p >= OVF) break;

			s += A[vec[j]];
			if (j > i) s += vec[j] - vec[j - 1] - 1;

			ll ts = p / k;
			if (p % k == 0 && ts >= s) {
				ts -= s;
				ans += max(0ll, min(ts, (vec[i] - vec[i - 1] - 1)) - max(0ll, ts - (vec[j + 1] - vec[j] - 1)) + 1);
			}
		}


		if (k == 1) ans += C2(vec[i] - vec[i - 1]);
	}

	if (k == 1) ans += C2(vec[int(vec.size()) - 1] - vec[int(vec.size()) - 2]);
	cout << ans << endl;
	return 0;
}