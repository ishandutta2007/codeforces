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

int k, n, A[MAXN], ps[MAXN], ps_mn[MAXN];

inline bool can(int m) {
	for (int i = 1; i <= n; i++) {
		int x = -1;
		if (A[i] >= m) x = 1;
		ps[i] = ps[i - 1] + x;
		ps_mn[i] = min(ps_mn[i - 1], ps[i]);
		if (i >= k && ps[i] - ps_mn[i - k] > 0) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	int L = 1, R = n;
	while (L < R) {
		int mid = (L + R + 1) >> 1;
		if (can(mid)) L = mid;
		else R = mid - 1;
	}

	cout << L << endl;
	return 0;
}