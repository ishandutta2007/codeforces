#include <bits/stdc++.h>
 
using namespace std;

#pragma GCC optimize("O3,no-stack-protector,unroll-loops,fast-math")
 
typedef int ll;
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
 
const ll MAXN = 500 + 3;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7; // 99876597; // 1e9 + 9;

ll A[MAXN][MAXN], n, m, diff[26][2];
pair<ll, pll> dp[MAXN][26][26];

void print_cl(ll c1, ll c2) {
	for (int i = 0; i < m; i++) {
		if (i & 1) cout << char(c2 + 'a');
		else cout << char(c1 + 'a');
	}
	
	cout << endl;
} 

ll difff(ll i, ll c1, ll c2) {
	ll ans = 0;
	for (int j = 0; j < m; j++) {
		if (j & 1) {
			if (A[i][j] != c2) ans++;
		} else if (A[i][j] != c1) ans++;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			A[i][j] = c - 'a';
		}
	}

	for (int c1 = 0; c1 < 26; c1++) {
		for (int c2 = 0; c2 < 26; c2++) {
			dp[0][c1][c2] = {INF, {INF, INF}};
			if (c1 != c2) dp[0][c1][c2] = {difff(0, c1, c2), {0, 0}};
		}
	}

	for (int i = 1; i < n; i++) {
		for (int c = 0; c < 26; c++) {
			diff[c][0] = diff[c][1] = 0;
			for (int j = 0; j < m; j++)
				if (A[i][j] != c) diff[c][j & 1]++;
		}

		for (int c1 = 0; c1 < 26; c1++) {
			for (int c2 = 0; c2 < 26; c2++) {
				ll df = diff[c1][0] + diff[c2][1];
				dp[i][c1][c2] = {INF, {INF, INF}};
				for (int pc1 = 0; pc1 < 26; pc1++) {
					for (int pc2 = 0; pc2 < 26; pc2++) {
						if (c1 == c2 || c1 == pc1 || c2 == pc2) continue;
						dp[i][c1][c2] = min(dp[i][c1][c2], {dp[i - 1][pc1][pc2].X + df, {pc1, pc2}});				
					}
				}
			}
		}
	}

	stack<pll> st;
	pll p = {0, 0};
       	ll ind = n - 1, ans = INF;
	for (int c1 = 0; c1 < 26; c1++)
		for (int c2 = 0; c2 < 26; c2++)
			if (dp[ind][c1][c2] < dp[ind][p.X][p.Y]) p = {c1, c2}, ans = dp[ind][p.X][p.Y].X;
	while (ind >= 0) {
		st.push(p);
		p = dp[ind][p.X][p.Y].Y;
		ind--;
	}

	cout << ans << endl;
	while (!st.empty()) print_cl(st.top().X, st.top().Y), st.pop();
	return 0;
}