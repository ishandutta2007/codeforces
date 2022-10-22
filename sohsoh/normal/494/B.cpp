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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int F[MAXN], ps[MAXN], L[MAXN], dp[MAXN];
string s, t;

inline void Calc(string s) {
	int n = s.size(), k = 0;
	for (int i = 1; i < n; i++) {
		while (k && s[i] != s[k])
			k = F[k - 1];
		k += (s[i] == s[k]);
		F[i] = k;
	}
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> s >> t;
	Calc(t + "#" + s);
	for (int i = 0; i < s.size(); i++) F[i] = F[i + t.size() + 1];

	int n = t.size();
	L[1] = (F[0] == n ? 1 : -1);
	for (int i = 2; i <= s.size(); i++)
		L[i] = (F[i - 1] == n ? i - t.size() + 1 : L[i - 1]);
	dp[0] = ps[0] = 1;
	for (int i = 1; i <= s.size(); i++) {
		dp[i] = dp[i - 1];
	       	if (L[i] != -1) {
			dp[i] += ps[L[i] - 1];
			if (dp[i] >= MOD) dp[i] -= MOD;
		}

		ps[i] = ps[i - 1] + dp[i];
		if (ps[i] >= MOD) ps[i] -= MOD;
	}
	
	cout << (dp[s.size()] - 1 + MOD) % MOD << endl;
	return 0;
}