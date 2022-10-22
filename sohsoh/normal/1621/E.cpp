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

ll A[MAXN], n, m, T[MAXN], S[MAXN];
vector<ll> vec[MAXN];
bool B[MAXN][3];
int ps[MAXN][3];
vector<bool> ans[MAXN];

inline bool cmp(pair<pll, int> a, pair<pll, int> b) { // s, t
	return a.X.X * b.X.Y < b.X.X * a.X.Y;
}

inline void solve() {
	for (int i = 0; i < m + 10; i++) {
		ans[i].clear();
		vec[i].clear();
		S[i] = 0;
		T[i] = 0;
		ps[i][0] = ps[i][1] = ps[i][2] = B[i][0] = B[i][1] = B[i][2] = 0;
		A[i] = 0;
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1, greater<ll>());
	swap(n, m);
	reverse(A + 1, A + n + 1);

	vector<pair<pll, int>> V;
	V.push_back({{-1, 1}, 0});
	for (int i = 1; i <= n; i++) {
		cin >> T[i];
		for (int j = 1; j <= T[i]; j++) {
			ll x;
			cin >> x;
			S[i] += x;
			vec[i].push_back(x);
		}

		V.push_back({{S[i], T[i]}, i});
	}

	sort(all(V), cmp);
	for (int i = 1; i <= n; i++) {
		B[i][0] = !cmp({{A[i - 1], 1}, 1}, V[i]);
		B[i][1] = !cmp({{A[i], 1}, 1}, V[i]);
		B[i][2] = !cmp({{A[i + 1], 1}, 1}, V[i]);
		ps[i][0] = ps[i - 1][0] + B[i][0];
		ps[i][1] = ps[i - 1][1] + B[i][1];
		ps[i][2] = ps[i - 1][2] + B[i][2];
	}

	for (int i = 1; i <= n; i++) {
		ll t = V[i].X.Y - 1;
		int ind = V[i].Y;
		for (int e : vec[V[i].Y]) {
			ll s = V[i].X.X - e;
			int j = upper_bound(all(V), make_pair(make_pair(s, t), 0), cmp) - V.begin();
			j--;

			if (j < i) ans[ind].push_back((ps[j][1] == j) && ps[n][1] - ps[i][1] == n - i && 
					ps[i - 1][2] - ps[j][2] == i - j - 1 && (!cmp({{A[j + 1], 1}, 1}, {{s, t}, 0})));
			if (j > i) ans[ind].push_back(ps[i][1] == i && ps[n][1] - ps[j][1] == n - j && // i - 1 
					ps[j][0] - ps[i][0] == j - i && (!cmp({{A[j], 1}, 1}, {{s, t}, 0})));
			if (i == j) ans[ind].push_back(ps[i - 1][1] == i - 1 && ps[n][1] - ps[i][1] == n - i &&
					(!cmp({{A[i], 1}, 1}, {{s, t}, 0})));

		}
	}

	for (int i = 1; i <= n; i++) {
		for (bool b : ans[i])
			cout << int(b);
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}