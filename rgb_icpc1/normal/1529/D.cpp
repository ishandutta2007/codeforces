#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1000005;
int dp[N], s[N];

bool flg[N];
vector<int> prime;
void sieve(int n) {
	int i, j;
	flg[1] = 1;
	for (i = 2; i <= n; i++) {
		if (flg[i]) continue;
		for (j = i * 2; j <= n; j += i) flg[j] = 1;
	}
	for (int i = 1; i <= n; i ++) if (!flg[i]) prime.push_back(i);
}

int main() {
	sieve(N - 1);
	dp[1] = 1;
	dp[2] = 3;
	s[2] = 4;
	int pn = prime.size();
	for (int i = 3; i < N; i ++) {
		dp[i] = s[i - 1];
		int tot = 1;
		int k = i;
		for (int j = 0; j < pn && prime[j] * prime[j] <= k; j ++) {
			if (i % prime[j]) continue;
			int cnt = 0;
			while (k % prime[j] == 0) {
				k /= prime[j];
				cnt ++;
			}
			tot = 1LL * tot * (cnt + 1) % MOD;
		}
		if (!flg[k]) {
			tot = 1LL * tot * 2 % MOD;
		}
		(dp[i] += tot) %= MOD;
		s[i] = (s[i - 1] + dp[i]) % MOD;
	}
	int n;
	cin >> n;
	cout << dp[n] << endl;
}