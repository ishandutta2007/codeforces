#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

const ll MAXN = 2e5 + 10;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const int LOG = 25;

int st[MAXN][LOG], st2[MAXN][LOG], log_t[MAXN], n, A[MAXN];

inline int max_range(int L, int R) { int j = log_t[R - L + 1]; return max(st2[L][j], st2[R - (1 << j) + 1][j]); }
inline int min_range(int L, int R) { int j = log_t[R - L + 1]; return min(st[L][j], st[R - (1 << j) + 1][j]); }

int solve() {
	for (int i = 0; i < n + 10; i++) for (int j = 0; j < LOG; j++) st[i][j] = INF, st2[i][j] = -INF;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i], st[i][0] = A[i], st2[i][0] = A[i];
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			st2[i][j] = max(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
		}
	}

	for (int i = 0; i < n - 2; i++) {
		int x = max_range(0, i);
		int L = i + 1, R = n - 2;
		while (L < R) {
			int mid = (L + R) >> 1;
			int ml = min_range(i + 1, mid);
			int mr = max_range(mid + 1, n - 1);
			if (x == ml && x == mr) return cout << "YES" << endl << i + 1 << sep << mid - i << sep << n - mid - 1 << endl, 0;
			if (ml > x || mr > x) L = mid + 1;
			else R = mid;
		}

		
		int ml = min_range(i + 1, L);
		int mr = max_range(L + 1, n - 1);
		if (x == ml && x == mr) return cout << "YES" << endl << i + 1 << sep << L - i << sep << n - L - 1 << endl, 0;
	}

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	log_t[1] = 0;
	for (int i = 2; i < MAXN; i++) log_t[i] = log_t[i / 2] + 1;
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < LOG; j++) st[i][j] = INF, st2[i][j] = -INF;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}