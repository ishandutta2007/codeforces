#include <bits/stdc++.h>

using namespace std;

const int kN = 3007;
const long long kMod = 998244353;

pair<long long, bool> dp[kN][kN];
string s, t;

long long get_dp(int l, int r){
	if(r >= s.size())
		return 0;
	if(r - l + 1 == s.size())
		return l == 0 && r >= (int)t.size() - 1;

	auto &[answer, solved] = dp[l][r];
	if(solved)
		return answer;

	solved = true;
	answer = 0;

	if(l == 0 && r >= (int)t.size() - 1){
		answer++;
		answer %= kMod;
	}

	if(r >= (int)t.size() - 1){
		answer += get_dp(l, r + 1);
		answer %= kMod;
	}
	else{
		if(t[r + 1] == s[r - l + 1]){
			answer += get_dp(l, r + 1);
			answer %= kMod;
		}
	}

	if(l != 0){
		if(l - 1 >= t.size() || t[l - 1] == s[r - l + 1]){
			answer += get_dp(l - 1, r);
			answer %= kMod;
		}
	}

	//cout << l << " " << r << " - " << answer << " answer" << endl; 
	return answer;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> t;

	long long answer = 0;
	for(int i = 0; i < s.size(); ++i){
		if(i >= (int)t.size() || s[0] == t[i]){
			answer += 2 * get_dp(i, i);
			answer %= kMod;
		}
	}

	cout << answer << "\n";
	return 0;
}