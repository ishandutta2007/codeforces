#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

string s;
int n, P[MAXN], rnk[MAXN][LOG], ind, L[MAXN], R[MAXN], A[MAXN];

inline bool cmp(int x, int y) {
	if (rnk[x][ind - 1] != rnk[y][ind - 1]) return rnk[x][ind - 1] < rnk[y][ind - 1];
	if (max(x, y) + (1 << (ind - 1)) >= n) return x > y;
	return rnk[x + (1 << (ind - 1))][ind - 1] < rnk[y + (1 << (ind - 1))][ind - 1];
}

inline void build() {
	for (int i = 0; i < n; i++) P[i] = i, rnk[i][0] = s[i];
	for (ind = 1; ind < LOG; ind++) {
		sort(P, P + n, cmp);
		rnk[P[0]][ind] = 0;
	
		for (int i = 1; i < n; i++)
			rnk[P[i]][ind] = rnk[P[i - 1]][ind] + cmp(P[i - 1], P[i]);
	}
}

inline int LCP(int x, int y) {
	int ans = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		if (x < n && y < n && rnk[x][i] == rnk[y][i]) {
			ans += (1 << i);
			x += (1 << i);
			y += (1 << i);
		}
	}

	return ans;
}

inline void solve() {
	cin >> s;
	n = s.size();
	build();

	for (int i = 0; i < n - 1; i++)
		A[i] = LCP(P[i], P[i + 1]);

	for (int i = 0; i < n - 1; i++)
		for (L[i] = i - 1; L[i] >= 0 && A[i] <= A[L[i]]; L[i] = L[L[i]]);
	for (int i = n - 2; i >= 0; i--)
		for (R[i] = i + 1; R[i] < n - 1 && A[i] < A[R[i]]; R[i] = R[R[i]]);

	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += 1ll * (i - L[i]) * (R[i] - i) * A[i];
	ans += ans + 1ll * n * (n + 1) / 2;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}