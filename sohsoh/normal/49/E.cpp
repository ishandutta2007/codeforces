#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 50 + 10;

string s, t;
int n, m, k, dp[MAXN][MAXN];
vector<pll> adj[MAXN];
bool f_s[MAXN][MAXN][26], f_t[MAXN][MAXN][26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	n = s.size(), m = t.size();
	s = "." + s, t = "." + t;

	cin >> k;
	for (int i = 1; i <= k; i++) {
		char c, a, b;
		cin >> c >> a >> b >> a >> b;
		adj[c - 'a'].push_back({a - 'a', b - 'a'});
	}

	for (int i = 1; i <= n; i++)
		f_s[i][i][s[i] - 'a'] = true;	
	for (int i = 1; i <= m; i++)
		f_t[i][i][t[i] - 'a'] = true;

	for (int l = n; l > 0; l--)
		for (int r = l + 1; r <= n; r++)
			for (int mid = l; mid < r; mid++)
				for (int x = 0; x < 26; x++)
					for (pll e : adj[x])	
						f_s[l][r][x] |= (f_s[l][mid][e.X] && f_s[mid + 1][r][e.Y]);
	for (int l = m; l > 0; l--)
		for (int r = l + 1; r <= m; r++)
			for (int mid = l; mid < r; mid++)
				for (int x = 0; x < 26; x++)
					for (pll e : adj[x])
						f_t[l][r][x] |= (f_t[l][mid][e.X] && f_t[mid + 1][r][e.Y]);
	
	for (int i = 1; i < MAXN; i++)
		dp[0][i] = dp[i][0] = MAXN;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = MAXN;
			for (int a = 1; a <= i; a++)
				for (int b = 1; b <= j; b++)
					for (int e = 0; e < 26; e++)
						if (f_s[a][i][e] && f_t[b][j][e])
							dp[i][j] = min(dp[i][j], dp[a - 1][b - 1] + 1);
		}
	}

	cout << (dp[n][m] > n ? -1 : dp[n][m]) << endl;
	return 0;
}