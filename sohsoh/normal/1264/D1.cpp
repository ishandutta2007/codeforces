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

const ll MAXN = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

int n, S[MAXN][MAXN], E[MAXN][MAXN];
string s;

void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	s = '.' + s;
	S[0][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (s[i] == '(' && j > 0) mkey(S[i][j] = S[i - 1][j - 1]);
			else if (s[i] == ')') S[i][j] = S[i - 1][j];
			else if (s[i] == '?') {
				S[i][j] = S[i - 1][j];
				if (j) mkey(S[i][j] += S[i - 1][j - 1]);
			}
		}
	}

	for (int i = n; i > 0; i--)
		for (int j = 0; j <= n; j++)
			if (s[i] == '?' || s[i] == ')') 
				mkey(S[i][j] -= S[i - 1][j]);

	E[n + 1][0] = 1;
	for (int i = n; i > 0; i--) {
		for (int j = 0; j <= n; j++) {
			if (s[i] == ')' && j > 0) E[i][j] = E[i + 1][j - 1];
			else if (s[i] == '(') E[i][j] = E[i + 1][j];
			else if (s[i] == '?') {
				E[i][j] = E[i + 1][j];
				if (j) mkey(E[i][j] += E[i + 1][j - 1]);
			}
		}
	}

	for (int i = n; i > 0; i--) {
		for (int j = n; j > 0; j--) {
			mkey(E[i][j] += E[i][j + 1]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int d = 1; d <= n; d++) 
			mkey(ans += 1ll * S[i][d] * E[i + 1][d] % MOD);
	cout << ans << endl;
	return 0;
}