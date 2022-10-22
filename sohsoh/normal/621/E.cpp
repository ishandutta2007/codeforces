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
const ll INF = 1e7 + 10;
const ll MOD = 1e9 + 7;

struct matrix {
	vector<vector<ll>> a;
	int n, m;

	matrix(int n, int m): n(n), m(m) {
		a.resize(n);
		for (int i = 0; i < n; i++)
			a[i].resize(m, 0);
	}

	matrix operator*(const matrix& b) {
		matrix ans = matrix(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++)
					ans.a[i][j] = (ans.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
			}
		}

		return ans;
	}
};

int n, b, k, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> b >> k >> x;
	matrix T(x, x), ans(x, x);
	ans.a[0][0] = 1;

	for (int t = 0; t < n; t++) {
		int f;
		cin >> f;
		for (int i = 0; i < x; i++)
			T.a[i][(i * 10 + f) % x]++;	
	}

	while (b) {
		if (b & 1) ans = ans * T;
		b >>= 1;
		T = T * T;
	}

	cout << ans.a[0][k] << endl;
	return 0;
}