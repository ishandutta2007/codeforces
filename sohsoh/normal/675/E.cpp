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

int A[MAXN], n;
pll sg[MAXN];
ll dp[MAXN];

void build(int l = 1, int r = n + 1, int v = 1) {
	if (l == r) sg[v] = {A[l], l};
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

pll query(int ql, int qr, int l = 1, int r = n + 1, int v = 1) {
	if (ql > r || qr < l) return {-1, -1};
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return max(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) cin >> A[i];
	
	A[n] = n;
	build();
	ll ans = 0;
	for (int i = n - 1; i > 0; i--) {
		int x = query(i + 1, A[i]).Y;
		dp[i] = dp[x] - (A[i] - x) + n - i;
		ans += dp[i];
	}

	cout << ans << endl;
	return 0;
}