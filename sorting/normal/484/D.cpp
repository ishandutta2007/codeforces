#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 7;

long long a[N], b[N];
pair<long long, bool> dp[N][2];

long long solve(int pos, bool mx){
	if(pos == 0){
		return 0;
	}
	if(dp[pos][mx].second){
		return dp[pos][mx].first;
	}

	dp[pos][mx].second = true;

	dp[pos][mx].first = max(solve(pos - 1, 0), solve(pos - 1, 1));
	if(mx){
		dp[pos][mx].first = max(dp[pos][mx].first, solve(pos - 1, mx) + b[pos]);
	}
	else{
		dp[pos][mx].first = max(dp[pos][mx].first, solve(pos - 1, mx) - b[pos]);
	}

	//cout << dp[pos][mx].first << " = " << pos << " " << mx << endl;

	return dp[pos][mx].first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	b[0] = 0;
	for(long long i = 0; i < n - 1; i++){
		b[i + 1] = a[i] - a[i+1]; 
	}
	b[n] = 0;

	cout << max(solve(n - 1, 0), solve(n - 1, 1)) << "\n";

	return 0;
}