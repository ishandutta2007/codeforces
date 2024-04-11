#include <bits/stdc++.h>
 
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll, pair<pair<ll, ll>, ll>> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 200 + 20;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// 0: )
// 1: (
// 2: ()

pll dp[MAXN][MAXN][2 * MAXN];
ll n, m;

void upd(pll& x, pll y) {
	x = min(x, y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) for (int k = 0; k < 2 * MAXN; k++) dp[i][j][k] = {INF, {{INF, INF}, INF}};
	dp[0][0][0] = {0, {{-1, -1}, -1}};
	
	string s, t;
	cin >> s >> t;
	for (int i = 0; i <= s.size(); i++) {
		for (int j = 0; j <= t.size(); j++) {
			if (i == 0 && j == 0) continue;
			for (int k = 0; k < 2 * MAXN - 3; k++) {
				if (i > 0) { 
					if (s[i - 1] == '(') { if (k > 0) upd(dp[i][j][k], {dp[i - 1][j][k - 1].X + 1, {{i - 1, j}, 1}}); }
					else upd(dp[i][j][k], {dp[i - 1][j][k + 1].X + 1, {{i - 1, j}, 0}}), upd(dp[i][j][k], {dp[i - 1][j][k].X + 2, {{i - 1, j}, 2}}); 
				}

				if (j > 0) {
					if (t[j - 1] == '(') { if (k > 0) upd(dp[i][j][k], {dp[i][j - 1][k - 1].X + 1, {{i, j - 1}, 1}}); }
					else upd(dp[i][j][k], {dp[i][j - 1][k + 1].X + 1, {{i, j - 1}, 0}}),  upd(dp[i][j][k], {dp[i][j - 1][k].X + 2, {{i, j - 1}, 2}});
				}

				if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {	
					if (s[i - 1] == '(') { if (k > 0) upd(dp[i][j][k], {dp[i - 1][j - 1][k - 1].X + 1, {{i - 1, j - 1}, 1}}); }
					else upd(dp[i][j][k], {dp[i - 1][j - 1][k + 1].X + 1, {{i - 1, j - 1}, 0}}), upd(dp[i][j][k], {dp[i - 1][j - 1][k].X + 2, {{i - 1, j - 1}, 2}}); 	
				}


			}
		}
	}

	string ans = "";

	for (int i = 0; i < 2 * MAXN; i++) {
		if (dp[s.size()][t.size()][i].X > 1e5) continue;
		ll x = s.size(), y = t.size(), z = i;
		stack<char> st;
		for (int j = 0; j < i; j++) st.push(')');
		while (x > 0 || y > 0) {
			ll t = dp[x][y][z].Y.Y;
			ll nx = dp[x][y][z].Y.X.X, ny = dp[x][y][z].Y.X.Y;
			if (t == 0) z++, st.push(')');
			else if (t == 1) z--, st.push('(');
			else st.push(')'), st.push('(');

			x = nx, y = ny;
		}

		string tans = "";
		while (!st.empty()) tans.push_back(st.top()), st.pop();
		if (tans.size() < ans.size() || ans.empty()) ans = tans;
	}

	cout << ans << endl;
	return 0;
}