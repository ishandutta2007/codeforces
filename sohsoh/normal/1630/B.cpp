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

int lst, n, k, cnt[MAXN], ps[MAXN], A[MAXN];

inline void solve() {
	// clearrrrr lst n cnt
	for (int i = 0; i < n + 5; i++) {
		cnt[i] = ps[i] = A[i] = 0;
	}
	lst = n = k = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}

	lst = -n;
	pll ans = {-1, n + 1};
	int r = 0;
	for (int l = 1; l <= n; l++) {
		while (r < l || (r < n && lst < k)) {
			r++;
			lst += 2 * cnt[r];
		}

		if (lst >= k) {
			if (r - l < ans.Y - ans.X)
				ans = {l, r};
		}

		lst -= 2 * cnt[l];
	}

	cout << ans.X << sep << ans.Y << endl;
	int f = 0;
	vector<int> vec = {0};

	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1];
		if (A[i] >= ans.X && A[i] <= ans.Y) ps[i]++;
		else ps[i]--;

		if (ps[i] > f && f < k - 1) {
			f++;
			vec.push_back(i);
		}
	}

	vec.push_back(n);
	for (int i = 0; i < k; i++)
		cout << vec[i] + 1 << sep << vec[i + 1] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}