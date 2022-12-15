#include <bits/stdc++.h>

using namespace std;

const int max_n = 1007;
const int max_sum = 1e4 + 7;
const int mod = 1e9 + 7;

pair<int, bool> dp[max_n][max_sum][2];
int a[max_n];

int solve(int pos, int sum, bool b){
	if(pos == -1){
		if(b & sum == 0){
			return 1;
		}
		return 0;
	}

	pair<int, bool> &state = dp[pos][sum][b]; 

	if(state.second){
		return state.first;
	}

	state.second = true;

	if(!b){
		state.first = solve(pos - 1, sum, b);
	}

	state.first += solve(pos - 1, max(sum - a[pos], a[pos] - sum), true);
	state.first %= mod;
	state.first += solve(pos - 1, sum + a[pos], true);
	state.first %= mod;
	
	if(b & sum == 0){
		state.first++;
	}

	state.first %= mod;

	//cout << state.first << " = " << pos << " " << sum << " " << b << endl;

	return state.first;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << solve(n - 1, 0, false) << "\n";

	return 0;
}