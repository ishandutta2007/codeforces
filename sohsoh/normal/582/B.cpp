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

const ll MAXN = 1e2 + 10;
const ll INF = 1e7 + 10;

struct matrix {
	vector<vector<int>> a;
	int n, m;

	matrix(int n, int m): n(n), m(m) {
		a.resize(n);
		for (int i = 0; i < n; i++)
			a[i].resize(m, 0);
	}

	matrix operator*(const matrix& b) {
		matrix ans = matrix(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = i; j < b.m; j++) {
				ans.a[i][j] = 0;
				for (int k = i; k <= j; k++)
					ans.a[i][j] = max(ans.a[i][j], a[i][k] + b.a[k][j]);
			}
		}

		return ans;
	}
};

int n, t, A[MAXN], dp[MAXN];
vector<int> X;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> A[i], X.push_back(A[i]);
	sort(all(X));

	for (int i = 0; i < n; i++) A[i] = lower_bound(all(X), A[i]) - X.begin();

	matrix ans(n, n), F(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = 0; k < n; k++) {
				dp[k] = 0;
				if (A[k] < i || A[k] > j) continue;
				dp[k] = 1;
				for (int a = 0; a < k; a++)
					if (A[a] <= A[k])
						dp[k] = max(dp[k], dp[a] + 1);
				F.a[i][j] = max(F.a[i][j], dp[k]);
			}
		}
	}

	while (t) {
		if (t & 1) ans = ans * F;
		F = F * F;
		t >>= 1;
	}

	cout << ans.a[0][n - 1] << endl;
	return 0;
}