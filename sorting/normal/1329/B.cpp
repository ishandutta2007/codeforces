#include <bits/stdc++.h>

using namespace std;

const int kBits = 64;

long long dp[kBits], pow2_table[kBits];

void solve(){
	long long d, m;
	cin >> d >> m;

	long long x = 1, k = 0;
	while(x <= d){
		x <<= 1;
		++k;
	}
	--k;

	pow2_table[0] = 1;
	for(int i = 1; i <= k; ++i)
		pow2_table[i] = pow2_table[i - 1] * 2 % m;

	long long sum = 0;
	for(int bit = k; bit >= 0; --bit){
		if(bit == k){
			dp[bit] = (d - (1 << k) + 1) % m;
			sum += dp[bit];
			continue;
		}

		dp[bit] = (sum + 1) % m;
		dp[bit] *= pow2_table[bit];
		dp[bit] %= m;

		sum += dp[bit];
		sum %= m;
	}

	cout << sum << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}