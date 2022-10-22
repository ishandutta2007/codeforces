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
const ll MAXK = 20 + 2;
const ll INF = 8e18;

int cnt[MAXN], n, k, A[MAXN];
ll dp[MAXK][MAXN], cost = 0;

inline void add(int x) {
	cost += (cnt[A[x]]++);
}

inline void remove(int x) {
	cost -= (--cnt[A[x]]);
}

void solve(int ind, int l = 1, int r = n, int optl = 0, int optr = n) {
	if (r < l) return;

	int mid = (l + r) >> 1;
	mid = (l + r) >> 1;

	for (int i = max(optr + 1, l); i < mid; i++)
		add(i);

	ll mn = INF, opt = -1;
	add(mid);
	for (int i = min(optr, mid - 1); i >= optl; i--) {
		if (cost + dp[ind - 1][i] < mn) {
			mn = cost + dp[ind - 1][i];
			opt = i; 
		}

		add(i);
	}

	dp[ind][mid] = mn;

	// (optr, l)
	remove(mid);
	for (int i = optl; i <= min(optr, mid - 1); i++)
		remove(i);
	for (int i = max(optr + 1, l); i < mid; i++)
		remove(i);	

	// [optl, opt] -> [l, mid):  (opt, l)
	for (int i = min(l - 1, optr); i > opt; i--)
		add(i);
	solve(ind, l, mid - 1, optl, opt);
	for (int i = min(l - 1, optr); i > opt; i--)
		remove(i);

	// [opt, optr] -> (mid, r): (optr, mid]
	for (int i = max(l, optr + 1); i <= mid; i++)
		add(i);
	solve(ind, mid + 1, r, opt, optr);
	for (int i = max(l, optr + 1); i <= mid; i++)
		remove(i);	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
		
	for (int i = 1; i <= n; i++) {
		add(i);
		dp[1][i] = cost;
	}

	for (int i = 1; i <= n; i++)
		remove(i);

	for (int i = 2; i <= k; i++)
		solve(i);

	cout << dp[k][n] << endl;
	return 0;
}