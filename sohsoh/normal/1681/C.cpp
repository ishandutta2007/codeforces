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

int n, A[MAXN], B[MAXN], P[MAXN];

inline int solve() {
	cin >> n;
	vector<pair<pll, int>> vec;
	
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int i = 1; i <= n; i++) {
		cin >> B[i];
		vec.push_back({{A[i], B[i]}, i});
	}

	sort(all(vec));
	int mx = -1;

	for (int i = 1; i <= n; i++) {
		if (vec[i - 1].X.Y < mx) return cout << -1 << endl, 0;
		mx = vec[i - 1].X.Y;
		P[vec[i - 1].Y] = i;
	}

	vector<pll> ans;
	for (int i = 1; i <= n; i++) {
		if (P[i] == i) continue;
		for (int j = i + 1; j <= n; j++) {
			if (P[j] == i) {
				ans.push_back({i, j});
				swap(P[i], P[j]);
				break;
			}
		}
	}

	cout << ans.size() << endl;
	for (pll e : ans)
		cout << e.X << sep << e.Y << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}