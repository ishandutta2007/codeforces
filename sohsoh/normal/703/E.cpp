#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long ll;
typedef pair<int, ll> pll;

#pragma GCC optimize("O3,no-stack-protector,unroll-loops,fast-math")

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 2;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;
const ll MAXM = 6720;

int n;
ll k, A[MAXN];
pll dp[MAXN][MAXM];
bool dp_b[MAXN][MAXM];
vector<ll> V;
unordered_map<ll, ll> mp;


ll GCD(ll a, ll b) {
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return GCD(b, a % b);	
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i];
	if (k == 1) return cout << 1 << endl << min_element(A + 1, A + n + 1) - A << endl, 0;
	
	int sq = sqrt(k);
	for (int i = 1; i <= sq; i++) {
		if (k % i == 0) {
			V.push_back(i);
			if (k / i != i) V.push_back(k / i);
		}	
	}
	
	sort(all(V));
	int sz = V.size();
	for (int i = 0; i < sz; i++) mp.insert({V[i], i});

	for (int j = 1; j < sz; j++) dp[0][j] = {n + 1, INF};
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz; j++) {
			dp[i][j] = dp[i - 1][j];
			ll k = mp[V[j] / GCD(V[j], A[i])];
			pll ans = dp[i - 1][k];
			ans.X++;
			ans.Y += A[i];
			if (ans < dp[i][j]) {
				dp[i][j] = ans;
				dp_b[i][j] = true;
			}
		}
	}

	if (dp[n][V.size() - 1].X > n) return cout << -1 << endl, 0;
	
	vector<int> v;
	ll t = k, i = n;
	while (i) {
		int j = mp[t];
		if (dp_b[i][j]) {
			v.push_back(i);
			t /=  GCD(t, A[i]);
		}

		i--;
	}
	
	cout << v.size() << endl;
	for (int e : v) cout << e << sep;
	cout << endl;
	return 0;
}