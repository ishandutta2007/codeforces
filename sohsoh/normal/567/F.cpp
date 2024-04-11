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

const ll MAXN = 100 + 10;
ll n, k, dp[MAXN][MAXN], A[MAXN];
vector<pair<pll, int>> vec;

inline bool f(int l, int r, int a, int b) {
	for (auto e : vec) {
		int x = e.X.X, y = e.X.Y, c = e.Y;
		
		if (x != a && x != b && y != a && y != b) continue;
		if (x < l || x > r || y < l || y > r) continue;

		if (c == 1 && A[x] != A[y]) return false;
		if (c == 2 && A[x] >= A[y]) return false;
		if (c == 3 && A[x] > A[y]) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		string s;
		cin >> x >> s >> y;

		if (s == ">") s = "<", swap(x, y);
		if (s == ">=") s = "<=", swap(x, y);

		if (s == "=") vec.push_back({{min(x, y), max(x, y)}, 1});
		else if (s == "<") vec.push_back({{x, y}, 2});
		else if (s == "<=") vec.push_back({{x, y}, 3});
	}

	for (int i = n; i > 0; i--) {
		for (int l = 1; l <= 2 * n; l++) {
			int r = l + 2 * (n - i + 1) - 1;
			if (r > 2 * n) break;
			
			if (i == n) {
				A[l] = A[l + 1] = 1;
				if (f(l, r, l, l + 1)) dp[i][l] = 1;
				continue;
			}

			fill(A, A + MAXN, 2);
			A[l] = 1, A[l + 1] = 1;
			if (f(l, r, l, l + 1)) dp[i][l] = dp[i + 1][l + 2];


			fill(A, A + MAXN, 2);
			A[r] = 1, A[r - 1] = 1;
			if (f(l, r, r, r - 1)) dp[i][l] += dp[i + 1][l];

			fill(A, A + MAXN, 2);
			A[r] = 1, A[l] = 1;
			if (f(l, r, l, r)) dp[i][l] += dp[i + 1][l + 1];
		}
	}

	cout << dp[1][1] << endl;
	return 0;
}