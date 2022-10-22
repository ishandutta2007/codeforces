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
const ll MOD = 998244353; // 1e9 + 9;

int n;
ll dp[MAXN], D[MAXN], S;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			D[j]++;

	dp[1] = 1;
	cin >> n;

	S = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = D[i] + S;
		S += dp[i];
		S %= MOD;
		dp[i] %= MOD;
	}

	cout << dp[n] << endl;
	return 0;
}