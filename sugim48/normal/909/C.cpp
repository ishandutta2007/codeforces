#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int main() {
	int N; cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1;
	int cnt = 0;
	rep(t, N) {
		string s; cin >> s;
		if (s == "s") {
			vector<int> sum(N + 2);
			for (int x = N; x >= 0; x--)
				sum[x] = (sum[x + 1] + dp[x]) % MOD;
			rep(x, N + 1) dp[x] = 0;
			rep(x, N + 1) if (x + cnt <= N) dp[x + cnt] = sum[x];
			cnt = 0;
		}
		if (s == "f") cnt++;
	}
	int ans = 0;
	rep(x, N + 1) ans = (ans + dp[x]) % MOD;
	cout << ans << endl;
}