#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const long long inf = 1e18;

int n;
array<long long, 2> a[MAXN];
pair<long long, bool> dp[MAXN];
long long choice[MAXN], ans[MAXN];

long long solve_dp(int pos){
	if(pos == n){
		return 0ll;
	}
	if(dp[pos].second){
		return dp[pos].first;
	}

	dp[pos].second = true;
	dp[pos].first = inf;

	vector<long long> v = {pos + 3, pos + 4, pos + 5};

	for(long long x: v){
		if(x > n){
			continue;
		}
		long long curr = solve_dp(x) + a[x - 1][0] - a[pos][0];
		
		if(dp[pos].first > curr){
			dp[pos].first = curr;
			choice[pos] = x;
		}
	}

	return dp[pos].first;
}

void solve(){
	sort(a, a + n);
	solve_dp(0);
}

void write(){
	int curr = 0, cnt = 0;
	while(curr != n){
		++cnt;
		for(int i = curr; i < choice[curr]; ++i){
			ans[a[i][1]] = cnt;
		}
		curr = choice[curr];
	}

	cout << solve_dp(0) << " " << cnt << "\n";
	for(int i = 0; i < n; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

void read(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i][0];
		a[i][1] = i;
	}
}

int main(){
	read();
	solve();
	write();
}