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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, X[MAXN];
int ans[MAXN];
vector<pair<int, pair<int, bool>>> v, A[2];

inline int solve() {
	v.clear();
	A[0].clear();
	A[1].clear();
	cin >> n >> m;	
	fill(ans, ans + n + 10, -1);
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		X[i] = x;
		v.push_back({x, {i, false}});
	}


	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v[i].Y.Y = (c == 'R');
	}
	
	sort(all(v));
	for (auto e : v) {
		int ind = e.X & 1;
		if (!A[ind].empty() && A[ind].back().Y.Y && !e.Y.Y) ans[A[ind].back().Y.X] = ans[e.Y.X] = abs(e.X - A[ind].back().X) / 2, A[ind].pop_back();
		else A[ind].push_back(e);
	}

	for (int i = 0; i < 2; i++) {
		while (A[i].size() > 1 && A[i].back().Y.Y && A[i][A[i].size() - 2].Y.Y) {
			int t = m - A[i].back().X + (A[i].back().X - A[i][A[i].size() - 2].X) / 2;
			ans[A[i].back().Y.X] = t;
			A[i].pop_back();
			ans[A[i].back().Y.X] = t;
			A[i].pop_back();
		}

		reverse(all(A[i]));

		while (A[i].size() > 1 && !A[i].back().Y.Y && !A[i][A[i].size() - 2].Y.Y) {
			int t = A[i].back().X + abs(A[i].back().X - A[i][A[i].size() - 2].X) / 2;
			ans[A[i].back().Y.X] = t;
			A[i].pop_back();
			ans[A[i].back().Y.X] = t;
			A[i].pop_back();
		}

		if (A[i].size() > 1) {
			int x = min(A[i].back().X, m - A[i].front().X);
			int rem = max(A[i].back().X, m - A[i].front().X) - x;
		       	int t = x + rem + (m - rem) / 2;
			ans[A[i].front().Y.X] = ans[A[i].back().Y.X] = t;	
		}
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << sep;
	cout << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}