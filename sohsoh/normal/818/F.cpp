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
#define int 			    long long

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int n;

inline int calc(int k) {
	return n - k + min(1ll * k * (k - 1) / 2, 1ll * n - k);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		cin >> n;
		int L = 1, R = n;
		
		while (R - L > 10) {
			int d = (R - L) / 3, mid1 = L + d, mid2 = R - d;
			if (calc(mid1) > calc(mid2)) R = mid2;
			else L = mid1;
		}

		int ans = 0;
		while (L <= R) {
			ans = max(ans, calc(L));
			L++;
		}

		cout << ans << endl;
	}
	return 0;
}