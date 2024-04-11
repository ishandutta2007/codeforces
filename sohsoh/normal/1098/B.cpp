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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<vector<char>> G;
ll n, m;

pair<ll, vector<char>> min_row(ll i, char c1, char c2) {
	pair<ll, vector<char>> ans1, ans2;
	ans1.X = ans2.X = 0;
	for (int j = 0; j < m; j++) {
		if (j & 1) ans1.Y.push_back(c2);
		else ans1.Y.push_back(c1);
		if (G[i][j] == ans1.Y.back()) ans1.X++;
	}

	for (int j = 0; j < m; j++) {
		if (j & 1) ans2.Y.push_back(c1);
		else ans2.Y.push_back(c2);
		if (G[i][j] == ans2.Y.back()) ans2.X++;
	}

	return max(ans1, ans2);
}

pair<ll, vector<char>> min_col(ll j, char c1, char c2) {
	pair<ll, vector<char>> ans1, ans2;
	ans1.X = ans2.X = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) ans1.Y.push_back(c2);
		else ans1.Y.push_back(c1);
		if (G[i][j] == ans1.Y.back()) ans1.X++;
	}

	for (int i = 0; i < n; i++) {
		if (i & 1) ans2.Y.push_back(c1);
		else ans2.Y.push_back(c2);
		if (G[i][j] == ans2.Y.back()) ans2.X++;
	}

	return max(ans1, ans2);
}

pair<ll, vector<vector<char>>> row(char c1, char c2) {
	pair<ll, vector<vector<char>>> ans;
	ans.X = 0;
	char c3 = 'N', c4 = 'N';
	if (c1 != 'A' && c2 != 'A' && c3 != 'A') c4 = 'A';
	if (c1 != 'T' && c2 != 'T' && c3 != 'T') c4 = 'T';
	if (c1 != 'C' && c2 != 'C' && c3 != 'C') c4 = 'C';
	if (c1 != 'G' && c2 != 'G' && c3 != 'G') c4 = 'G';
	if (c1 != 'A' && c2 != 'A' && c4 != 'A') c3 = 'A';
	if (c1 != 'T' && c2 != 'T' && c4 != 'T') c3 = 'T';
	if (c1 != 'C' && c2 != 'C' && c4 != 'C') c3 = 'C';
	if (c1 != 'G' && c2 != 'G' && c4 != 'G') c3 = 'G';
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			auto P = min_row(i, c1, c2);
			ans.X += P.X;
			ans.Y.push_back(P.Y);
		} else {	
			auto P = min_row(i, c3, c4);
			ans.X += P.X;
			ans.Y.push_back(P.Y);	
		}
	}

	return ans;
}

void ins_col(vector<vector<char>>& v, vector<char> c, ll j) {
	for (int i = 0; i < n; i++) v[i][j] = c[i];
}

pair<ll, vector<vector<char>>> col(char c1, char c2) {	
	pair<ll, vector<vector<char>>> ans;
	ans.X = 0;
	char c3 = 'N', c4 = 'N';
	if (c1 != 'A' && c2 != 'A' && c3 != 'A') c4 = 'A';
	if (c1 != 'T' && c2 != 'T' && c3 != 'T') c4 = 'T';
	if (c1 != 'C' && c2 != 'C' && c3 != 'C') c4 = 'C';
	if (c1 != 'G' && c2 != 'G' && c3 != 'G') c4 = 'G';
	if (c1 != 'A' && c2 != 'A' && c4 != 'A') c3 = 'A';
	if (c1 != 'T' && c2 != 'T' && c4 != 'T') c3 = 'T';
	if (c1 != 'C' && c2 != 'C' && c4 != 'C') c3 = 'C';
	if (c1 != 'G' && c2 != 'G' && c4 != 'G') c3 = 'G';
	
	ans.Y.resize(n);
	for (int i = 0; i < n; i++) ans.Y[i].resize(m);

	for (int j = 0; j < m; j++) {
		if (j & 1) {
			auto P = min_col(j, c1, c2);
			ans.X += P.X;
			ins_col(ans.Y, P.Y, j);
		} else {	
			auto P = min_col(j, c3, c4);
			ans.X += P.X;
			ins_col(ans.Y, P.Y, j);	
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	G.resize(n);
	for (int i = 0; i < n; i++) {
		G[i].resize(m);
		for (int j = 0; j < m; j++) cin >> G[i][j];
	}

	pair<ll, vector<vector<char>>> ans;
	ans = row('A', 'G');
	ans = max(ans, row('A', 'C'));
	ans = max(ans, row('A', 'T'));
	ans = max(ans, row('G', 'C'));
	ans = max(ans, row('G', 'T'));
	ans = max(ans, row('C', 'T'));	
	ans = max(ans, col('A', 'G'));
	ans = max(ans, col('A', 'C'));
	ans = max(ans, col('A', 'T'));
	ans = max(ans, col('G', 'C'));
	ans = max(ans, col('G', 'T'));
	ans = max(ans, col('C', 'T'));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << ans.Y[i][j];
		cout << endl;
	}	
	
	return 0;
}