#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 7;

int c[N], a[N];
pair<int, bool> dp[N][N];
int m = 0;

int solve(int l, int r){
	if(l == 0 && r == m-1){
		return 0;
	}

	if(dp[l][r].second){
		return dp[l][r].first;
	}

	dp[l][r].second = true;
	dp[l][r].first = m;

	if(l != 0){
		dp[l][r].first = min(dp[l][r].first, solve(l-1, r) + 1);
	}
	if(r != m-1){
		dp[l][r].first = min(dp[l][r].first, solve(l, r+1) + 1);
	}
	if(l != 0 && r != m-1 && a[l-1] == a[r+1]){
		dp[l][r].first = min(dp[l][r].first, solve(l-1, r+1) + 1);
	}

	return dp[l][r].first;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> c[i];
	}

	for(int i = 1; i < n; i++){
		if(c[i] != c[i-1]){
			a[m] = c[i-1];
			m++;
		}
	}

	a[m] = c[n-1];
	m++;

	int mn = m;

	for(int i = 0; i < m; i++){
		mn = min(mn, solve(i, i));
	}

	cout << mn << "\n";

	return 0;
}