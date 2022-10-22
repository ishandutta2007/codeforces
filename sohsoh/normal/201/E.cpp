#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

lll fact(lll n, lll k = 0) {
	lll ans = 1;
	for (int i = k + 1; i <= n; i++) ans = ans * i;
	return ans;
}

lll C(lll k, lll n) {
	if (k < n / 2) return fact(n, n - k) / fact(k);
	else return fact(n, k) / fact(n - k);
}

ll F(lll r, lll m) {
	lll c = r * m;
	lll cnt = 1;
	lll k = 1;
	while (c >= k && cnt < INF && k <= r) {
		lll t = min(c / k, C(k, r));
		c -= t * k;
		cnt += t;
		k++;
	}

	if (cnt > INF) return INF;
	return (ll)cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		ll L = 0, R = n - 1;
		while (L < R) {
			ll mid = (L + R) >> 1;
			if (F(mid, m) >= n) R = mid;
			else L = mid + 1;
		}

		cout << L << endl;
	}
	return 0;
}