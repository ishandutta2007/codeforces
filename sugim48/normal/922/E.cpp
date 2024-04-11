#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, int> d_i;
const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;
struct edge { int i, v, w; };

int main() {
	int N; cin >> N;
	ll W, B, X; cin >> W >> B >> X;
	vector<int> c(N);
	rep(i, N) cin >> c[i];
	vector<ll> cost(N);
	rep(i, N) cin >> cost[i];
	int M = 0;
	rep(i, N) M += c[i];
	vector<ll> dp(M + 1, -1);
	dp[0] = W;
	rep(i, N) {
		rep(t, c[i])
			for (int j = M; j >= 0; j--)
				if (dp[j] >= cost[i])
					dp[j + 1] = max(dp[j + 1], dp[j] - cost[i]);
		rep(j, M + 1)
			if (dp[j] != -1)
				dp[j] = min(dp[j] + X, W + j * B);
	}
	int ans;
	rep(j, M + 1) if (dp[j] != -1) ans = j;
	cout << ans << endl;
}