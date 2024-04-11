#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 5;
const ll SQ = 1e5;
const ll SQINV = MAXN + SQ + 10;

int n, k, A[MAXN], ptr[MAXN];

inline int solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	n = unique(A + 1, A + n + 1) - A - 1;

	int ans = A[n] / k;
	for (int mn = 1; mn <= min(SQ, A[1]); mn++) {
		int tans = 0;
		for (int i = 1; i <= n; i++) {
			int p = min(k, A[i] / mn);
			tans = max(tans, A[i] / p - mn);
		}

		ans = min(ans, tans);
	}
	
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int t = min(SQINV, k);
		pq.push({A[i] / t, i});
		mx = max(mx, A[i] / t);
		ptr[i] = t;
	}

	for (int mn = 1; mn <= A[n]; mn++) {
		while (pq.top().X < mn) {
			int ind = pq.top().Y;
			pq.pop();
			ptr[ind]--;
			if (ptr[ind] < 1) return cout << ans << endl, 0;
			
			pq.push({A[ind] / ptr[ind], ind});
			mx = max(mx, A[ind] / ptr[ind]);
		}
		
		ans = min(ans, mx - mn);
	}
	
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}