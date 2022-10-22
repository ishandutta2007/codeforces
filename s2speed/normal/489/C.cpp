#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string dp , pd;
	ll m , s , l , r;
	cin>>m>>s;
	if(m == 1 && s == 0){
		cout<<"0 0\n";
		return 0;
	}
	if(s < 1 || s > 9 * m){
		cout<<"-1 -1\n";
		return 0;
	}
	dp += '1';
	pd += '1';
	for(int i = 1 ; i < m ; i++){
		dp += '0';
		pd += '0';
	}
	l = 0;
	r = m - 1;
	for(int i = 2 ; i <= s ; i++){
		dp[l]++;
		if(dp[l] == '9'){
			l++;
		}
		pd[r]++;
		if(pd[r] == '9'){
			r--;
		}
	}
	cout<<pd<<' '<<dp<<'\n';
	return 0;
}