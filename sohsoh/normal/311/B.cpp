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

const ll MAXN = 1e5 + 10;
const ll MAXP = 100 + 10;
const ll INF = 8e18;

int n, m, p, d[MAXN], A[MAXN];
ll dp[MAXP][MAXN], ps[MAXN];

void solve(int ind, int l = 1, int r = m, int optl = 0, int optr = m) {
	if (r < l) return;
	int mid = (l + r) >> 1;

	ll opt = -1, mn = INF; 
	for (int i = optl; i <= min(optr, mid - 1); i++) {
		ll f = ps[i] - ps[mid] + 1ll * (mid - i) * A[mid] + dp[ind - 1][i];
		if (f < mn) {
			mn = f;
			opt = i;
		}
	}

	dp[ind][mid] = mn;
	solve(ind, l, mid - 1, optl, opt);
	solve(ind, mid + 1, r, opt, optr);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	for (int i = 2; i <= n; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}

	for (int i = 1; i <= m; i++) {
		int h, t;
		cin >> h >> t;
		A[i] = t - d[h];
	}

	sort(A + 1, A + m + 1);
	for (int i = 1; i <= m; i++) {
		ps[i] = ps[i - 1] + A[i];
		dp[1][i] = 1ll * i * A[i] - ps[i];
	}

	for (int i = 2; i <= min(p, m); i++)
		solve(i);
	
	cout << dp[min(p, m)][m] << endl;
	return 0;
}