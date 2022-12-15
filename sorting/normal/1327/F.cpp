#include <bits/stdc++.h>

using namespace std;

const long long kMod = 998244353;
const int kM = 5e5 + 7;
const int kBits = 31;

array<int, 3> cond[kM];
array<int, 3> sweepline[2 * kM];
int val[kM], cnt[kBits];

long long dp[kM], sum[kM];
int n, k, m;

long long get_sum(int l, int r){
	if(r == n + 1)
		return sum[l];
	return (sum[l] - sum[r + 1] + kMod) % kMod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> m;

	for(int i = 0; i < m; ++i){
		cin >> cond[i][0] >> cond[i][1] >> cond[i][2];
		--cond[i][0];
		--cond[i][1];
		sweepline[2 * i] = {cond[i][0], cond[i][2], 1};
		sweepline[2 * i + 1] = {cond[i][1] + 1, cond[i][2], -1};
	}

	sort(sweepline, sweepline + 2 * m);
	sort(cond, cond + m);
	int curr = 0;
	for(int i = 0; i < 2 * m; ++i){
		if(i != 0 && sweepline[i][0] != sweepline[i - 1][0]){
			for(int j = sweepline[i - 1][0]; j < sweepline[i][0]; ++j){
				val[j] = curr;
			}
		}

		if(sweepline[i][2] == 1){
			for(int j = 0; j < k; ++j){
				if((1 << j) & sweepline[i][1]){
					++cnt[j];
					if(cnt[j] == 1)
						curr ^= (1 << j);
				}
			}
		}
		else{
			for(int j = 0; j < k; ++j){
				if((1 << j) & sweepline[i][1]){
					--cnt[j];
					if(!cnt[j])
						curr ^= (1 << j);
				}
			}
		}
	}

	long long ans = 1;
	for(int bit = 0; bit < k; ++bit){
		int idx = m - 1, limit = n;
		dp[n + 1] = 1;
		if(val[n - 1] & (1 << bit))
			dp[n] = 0;
		else
			dp[n] = 1;
		sum[n + 1] = dp[n + 1];
		sum[n] = dp[n + 1] + dp[n];
		for(int i = n - 1; i >= 0; --i){
			while(idx >= 0 && cond[idx][0] >= i){
				if(!(cond[idx][2] & (1 << bit)))
					limit = min(limit, cond[idx][1]);
				--idx;
			}

			if(i != 0 && val[i - 1] & (1 << bit)){
				dp[i] = 0;
				sum[i] = sum[i + 1];
				continue;
			}

			dp[i] = get_sum(i + 1, limit + 1);
			dp[i] %= kMod;
			
			sum[i] = (dp[i] + sum[i + 1]) % kMod;
		}

		ans *= dp[0];
		ans %= kMod;
	}

	cout << ans << "\n";
}