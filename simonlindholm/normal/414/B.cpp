#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

vector<int> factors(int n) {
	vector<int> res;
	for (int i = 1; i <= n; ++i)
		if (n % i == 0)
			res.push_back(i);
	return res;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<long long> dp(N, 0), dp2 = dp;
	dp[0] = 1;
	vector<vector<int> > fact(N);
	for (int i = 0; i < N; ++i) {
		vector<int>& v = fact[i] = factors(i+1);
		for (int j = 0; j < (int)v.size(); ++j)
			v[j]--;
	}
	for (int i = 0; i < K; ++i) {
		dp2.assign(N, 0);
		for (int j = 0; j < N; ++j) {
			vector<int>& f = fact[j];
			long long& D = dp2[j];
			for (int k = 0; k < (int)f.size(); ++k) {
				int fi = f[k];
				D += dp[fi];
			}
			D %= MOD;
		}
		dp.swap(dp2);
	}
	long long res = 0;
	for (int i = 0; i < N; ++i) {
		res += dp[i];
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}