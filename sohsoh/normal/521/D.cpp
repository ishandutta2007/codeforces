// orz
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			    ll
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int A[MAXN], T[MAXN], n, m, k;
pll B[MAXN];
vector<pll> S[MAXN];
vector<pair<pll, int>> t_vec, vec;

inline bool cmp(pair<pll, int> a, pair<pll, int> b) {
	return a.X.X * b.X.Y > b.X.X * a.X.Y;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k >> n >> m;
	for (int i = 1; i <= k; i++) cin >> A[i];

	for (int j = 1; j <= n; j++) {
		int t, i, b;
		cin >> t >> i >> b;
		T[j] = t;
		
		if (t == 1) B[i] = max(B[i], {b, j});
		else if (t == 2) S[i].push_back({b, j});
		else t_vec.push_back({{b, 1}, j});
	}

	for (int i = 1; i <= k; i++)
		if (B[i].X > A[i])
			S[i].push_back({B[i].X - A[i], B[i].Y});

	for (int i = 1; i <= k; i++) {
		sort(all(S[i]), greater<pll>());
		ll x = A[i];
		for (pll e : S[i])
			t_vec.push_back({{x + e.X, x}, e.Y}), x += e.X;
	}

	for (auto e : t_vec) {
		e.X.X -= e.X.Y;
		if (e.X.X > 0) vec.push_back(e);
	}

	sort(all(vec), cmp);
	vector<pll> ans;

	for (int i = 0; i < min((int) vec.size(), m); i++)
		ans.push_back({T[vec[i].Y], vec[i].Y});
	sort(all(ans));

	cout << ans.size() << endl;
	for (pll e : ans)
		cout << e.Y << sep;
	cout << endl;
	return 0;
}