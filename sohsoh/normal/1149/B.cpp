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
 
const ll MAXN = 1e5 + 10;
const ll MAXK = 250 + 10;
const ll alpha = 26;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll P[alpha], F[MAXN][alpha], dp[MAXK][MAXK][MAXK];
ll n, q;
string s1 = "", s2 = "", s0 = "";

void upd(ll& a, ll b) {
	a = min(a, b);
}

void query() {
	char c;
	cin >> c;
	if (c == '+') {
		ll ind;
		cin >> ind >> c;
		ind--;
		if (ind == 0) {
			s0.push_back(c);
			for (int i = 0; i <= s1.size(); i++) {
				for (int j = 0; j <= s2.size(); j++) {
					ll k = s0.size();
					dp[i][j][k] = INF;
					if (i > 0) upd(dp[i][j][k], F[dp[i - 1][j][k]][s1[i - 1] - 'a'] + 1);
					if (j > 0) upd(dp[i][j][k], F[dp[i][j - 1][k]][s2[j - 1] - 'a'] + 1);
					if (k > 0) upd(dp[i][j][k], F[dp[i][j][k - 1]][s0[k - 1] - 'a'] + 1);
				}
			}
		} else if (ind == 1) {
			s1.push_back(c);
			for (int k = 0; k <= s0.size(); k++) {
				for (int j = 0; j <= s2.size(); j++) {
					ll i = s1.size();	
					dp[i][j][k] = INF;
					if (i > 0) upd(dp[i][j][k], F[dp[i - 1][j][k]][s1[i - 1] - 'a'] + 1);
					if (j > 0) upd(dp[i][j][k], F[dp[i][j - 1][k]][s2[j - 1] - 'a'] + 1);
					if (k > 0) upd(dp[i][j][k], F[dp[i][j][k - 1]][s0[k - 1] - 'a'] + 1);
				}
			}
		} else {
			s2.push_back(c);
			for (int k = 0; k <= s0.size(); k++) {
				for (int i = 0; i <= s1.size(); i++) {
					ll j = s2.size();	
					dp[i][j][k] = INF;
					if (i > 0) upd(dp[i][j][k], F[dp[i - 1][j][k]][s1[i - 1] - 'a'] + 1);
					if (j > 0) upd(dp[i][j][k], F[dp[i][j - 1][k]][s2[j - 1] - 'a'] + 1);
					if (k > 0) upd(dp[i][j][k], F[dp[i][j][k - 1]][s0[k - 1] - 'a'] + 1);
				}
			}
		}
	} else {
		ll ind;
		cin >> ind; ind--;
		if (ind == 0) s0.pop_back();	
		else if (ind == 1) s1.pop_back();	
		else if (ind == 2) s2.pop_back();	
	}

	dp[0][0][0] = 0;
	if (dp[s1.size()][s2.size()][s0.size()] <= n) cout << "YES" << endl;
       	else cout << "NO" << endl;
	return;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	string s;
	cin >> s;
	fill(P, P + alpha, n);
	for (int i = 0; i < MAXN; i++) fill(F[i], F[i] + alpha, n);
	for (int i = 0; i < MAXK; i++) for (int j = 0; j < MAXK; j++) for (int k = 0; k < MAXK; k++) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for (int i = n - 1; i >= 0; i--) {
		P[s[i] - 'a'] = i;
		for (int j = 0; j < alpha; j++) F[i][j] = P[j];
	}

	while (q--) query();
	return 0;
}