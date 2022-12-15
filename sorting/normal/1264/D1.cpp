#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2007;
const long long mod = 998244353;

struct state{
	long long sum, cnt;
	bool used;

	state(){
		sum = 0;
		cnt = 0;
		used = false;
	}
};

string s;
state dp[MAXN][MAXN];

state solve(int l, int r){
	if(l > r){
		state st = state();
		st.cnt = 1;
		st.sum = 0;
		st.used = false;
		return st;
	}
	if(l == r){
		dp[l][r] = state();
		dp[l][r].cnt = (s[l] == '?') ? 2 : 1;
		return dp[l][r];
	}
	if(dp[l][r].used)
		return dp[l][r];

	long long &sum = dp[l][r].sum;
	long long &cnt = dp[l][r].cnt;
	dp[l][r].used = true;

	sum = 0;
	if(s[l] != '('){
		sum += solve(l + 1, r).sum;
		sum %= mod;

		cnt += solve(l + 1, r).cnt;
		cnt %= mod;
	}
	if(s[r] != ')'){
		sum += solve(l, r - 1).sum;
		sum %= mod;

		cnt += solve(l, r - 1).cnt;
		cnt %= mod;
	}
	if(s[l] != '(' && s[r] != ')'){
		sum -= solve(l + 1, r - 1).sum;
		sum += mod;
		sum %= mod;

		cnt -= solve(l + 1, r - 1).cnt;
		cnt += mod;
		cnt %= mod;
	}
	if(s[l] != ')' && s[r] != '('){
		sum += solve(l + 1, r - 1).sum + solve(l + 1, r - 1).cnt;
		sum %= mod;

		cnt += solve(l + 1, r - 1).cnt;
		cnt %= mod;
	}
 
	return dp[l][r]; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	cout << solve(0, (int)s.size() - 1).sum << "\n";
}