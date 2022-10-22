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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], n, m, cnt[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			cnt[A[i] % m]++;
		}

		int ans = 0;
		for (int i = 1; i < (m + 1) / 2; i++) {
			if (cnt[i] == 0 && cnt[m - i] == 0) continue;
			ans++;
			if (cnt[i] == cnt[m - i]) continue;
			ans += max(cnt[i], cnt[m - i]) - min(cnt[i], cnt[m - i]) - 1;
		}

		if (m % 2 == 0 && cnt[m / 2] > 0) ans++;
		if (cnt[0] > 0) ans++;
		cout << ans << endl;
		
		for (int i = 0; i < m + 10; i++) cnt[i] = 0;
	}
	return 0;
}