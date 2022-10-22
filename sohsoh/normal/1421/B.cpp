#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 200 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

char A[MAXN][MAXN];

void print_ans(vector<pll> v) {
	cout << v.size() << endl;
	for (pll e : v) cout << e.X + 1 << sep << e.Y + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> A[i][j];
		
		vector<pll> ans;
		if (A[0][1] == A[1][0]) {
			if (A[n - 1][n - 2] == A[0][1]) ans.push_back({n - 1, n - 2});
			if (A[n - 2][n - 1] == A[0][1]) ans.push_back({n - 2, n - 1});
		} else if (A[n - 1][n - 2] == A[n - 2][n - 1]) {
			if (A[0][1] == A[n - 1][n - 2]) ans.push_back({0, 1});
			if (A[1][0] == A[n - 1][n - 2]) ans.push_back({1, 0});
		} else {
			if (A[0][1] == '1') ans.push_back({0, 1});
			else ans.push_back({1, 0});
			if (A[n - 1][n - 2] == '0') ans.push_back({n - 1, n - 2});
			else ans.push_back({n - 2, n - 1});
		}

		print_ans(ans);
	} 
	return 0;
}