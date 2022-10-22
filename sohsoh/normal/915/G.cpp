#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int SPF[MAXN], n, k;
ll poww_arr[MAXN];

inline void Prep() {
	for (int i = 1; i < MAXN; i++) SPF[i] = i;
	for (int i = 2; i < MAXN; i++) 
		if (SPF[i] == i) 
			for (int j = 2 * i; j < MAXN; j += i)
				if (SPF[j] == j)
					SPF[j] = i;
}

vector<pll> P_Factor(int n) {
	vector<pll> ans;
	while (n > 1) {
		int s = SPF[n];
		n /= s;
		if (ans.empty() || ans.back().X != s) ans.push_back({s, 0});
		ans.back().Y++;
	}

	return ans;
}

inline vector<pair<int, bool>> Divisors(int n) {
	vector<pll> D = P_Factor(n);
	vector<pair<int, bool>> ans = {{1, false}};
	for (pll e : D) {
		int ans_s = ans.size();
		for (int i = 0; i < ans_s; i++) {
			int x = ans[i].X;
			bool b = ans[i].Y;
			ans.push_back({x * e.X, !b});
		}
	}

	return ans;
}

inline ll poww(ll a, ll b, ll md) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = ans * a % md;
		a = a * a % md;	
		b >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Prep();

	cin >> n >> k;
	for (int i = 0; i < MAXN; i++) poww_arr[i] = poww(i, n, MOD);
	
	ll ans = 0, prev_ans = 0;
	for (int i = 1; i <= k; i++) {
		ll tans = prev_ans;
		vector<pair<int, bool>> D = Divisors(i);
		
		for (pair<int, bool> e : D) {
			ll delta = poww_arr[i / e.X] - poww_arr[i / e.X - 1];	
			delta = (delta + MOD) % MOD;
			if (e.Y) delta = MOD - delta;
			tans += delta;
			tans %= MOD;
		}	

		prev_ans = tans;
		ans += (i ^ tans); 
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}