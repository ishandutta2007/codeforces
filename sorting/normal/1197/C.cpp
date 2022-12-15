#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 3e5 + 7;
const long long inf = 1e9;

long long a[MAXN], dp[MAXN], cnt[MAXN];
long long n, k;

void solve(long long mid){
	dp[n] = 0;
	cnt[n] = 0;

	long long best_min, best_cnt;
	best_min = dp[n] + a[n - 1];
	best_cnt = cnt[n];
	for(long long i = n - 1; i >= 0; --i){
		if(best_min > dp[i + 1] + a[i]){
			best_min = dp[i + 1] + a[i];
			best_cnt = cnt[i + 1];
		}

		dp[i] = best_min - a[i] + mid;
		cnt[i] = best_cnt + 1;
		//cout << dp[i] << " " << cnt[i] << " " << best_min << " " << best_cnt << " i " << i << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(long long i = 0; i < n; ++i){
		cin >> a[i];
	}

	long long l = 0, r = inf;
	while(l != r){
		long long mid = (l + r) >> 1;

		solve(mid);
		solve(mid);
		//cout << mid << " " << dp[0] << endl;
		//cout << cnt[0] << endl;

		if(cnt[0] <= k){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	//cout << l << endl;

	solve(l);

	cout << dp[0] - k * l << "\n";

	return 0;
}