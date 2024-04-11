// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e2 + 10;
const ll INF = 1e9;

pair<int, pair<int, int>> dp[MAXN][MAXN][MAXN];
int F[MAXN];
string s, t, v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> t >> v;
	
	int k = 0;
	v = v + ')';
	s = '#' + s;
	t = '#' + t;
	for (int i = 1; i < v.size(); i++) {
		while (k && v[i] != v[k])
			k = F[k - 1];
		F[i] = (k += (v[i] == v[k]));
	}

	for (int i = 0; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			dp[0][i][j].X = dp[i][0][j].X = -INF;;

	for (int i = 1; i < s.size(); i++) {
		for (int j = 1; j < t.size(); j++) {
			for (int tk = 0; tk < v.size() - 1; tk++) {
				int k = tk;
				if (dp[i - 1][j][k].X > dp[i][j][k].X)
					dp[i][j][k] = {dp[i - 1][j][k].X, {0, k}};
				if (dp[i][j - 1][k].X > dp[i][j][k].X) 
					dp[i][j][k] = {dp[i][j - 1][k].X, {1, k}};

				if (s[i] == t[j]) {	
					while (k && s[i] != v[k])
						k = F[k - 1];
					k += (s[i] == v[k]);

					if (dp[i - 1][j - 1][tk].X + 1 > dp[i][j][k].X)
						dp[i][j][k] = {dp[i - 1][j - 1][tk].X + 1, {2, tk}};
				}
			}
		}
	}
	
	k = 0;
	int i = s.size() - 1, j = t.size() - 1;
	for (int tk = 1; tk < v.size() - 1; tk++)
		if (dp[i][j][tk].X > dp[i][j][k].X)
			k = tk;

	string ans;
	while (i && j) {
		int c = dp[i][j][k].Y.X;
		if (c == 0) i--;
		else if (c == 1) j--;
		else {
			ans += s[i];
			k = dp[i][j][k].Y.Y;
			i--;
			j--;
		}
	}

	reverse(all(ans));
	cout << (ans == "" ? "0" : ans) << endl;
	return 0;
}