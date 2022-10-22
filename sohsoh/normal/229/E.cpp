#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;
const ll INF = 4e18 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll S, n, m, D[MAXN], C[MAXN], req = 0, F[MAXN][MAXN];
vector<int> v, A[MAXN];
ld dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(10) << fixed;
	F[0][0] = 1;
	for (int j = 1; j < MAXN; j++) {
		for (int i = 0; i < MAXN; i++) {
			F[i][j] += F[i][j - 1];
			F[i][j] = min(INF, F[i][j]);
			if (i) F[i][j] += F[i - 1][j - 1];	
			F[i][j] = min(INF, F[i][j]);
		}
	}

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			A[i].push_back(x);
			v.push_back(x);
		}		
		
		sort(all(A[i]));
	}

	sort(all(v), greater<int>());
	if (n == v.size()) return cout << 1.0 << endl, 0;

	S = v[n];
	for (int i = 0; i < n; i++) 
		if (v[i] == S)
			req++;

	int rem = 0;
	for (int i = 1; i <= m; i++) {
		for (int e : A[i]) {
			if (e > S) D[i]++;
			else if (e == S) C[i]++, rem++;
		}
	}

	for (int i = 0; i < MAXN; i++) 
		for (int j = 0; j < MAXN; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	int cnt = 0;

	for (int i = 1; i <= m; i++) {
		int sz = A[i].size();	
		if (C[i] && req > 0) cnt++;
		else {
			for (int j = 0; j <= cnt; j++) 
				dp[i][j] = dp[i - 1][j] / F[D[i]][sz];
			continue;
		}

		for (int j = 0; j <= min(1ll * cnt, req); j++) {
			if ((req - j + 1) > rem) continue;
			if (j) dp[i][j] = dp[i - 1][j - 1] * (req - j + 1) / rem / F[D[i] + 1][sz];
			dp[i][j] += dp[i - 1][j] * (1 - ld(req - j) / rem) / F[D[i]][sz];
		}

		rem--;
	}
	
	cout << dp[m][req] << endl;
	return 0;
}