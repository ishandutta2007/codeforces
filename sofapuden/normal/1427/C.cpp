#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int r, n; cin >> r >> n;
	vector<array<int,3>> v;
	v.push_back({0,1,1});
	for(int i = 0 ; i < n; ++i){
		int a, b, c; cin >> a >> b >> c;
		v.push_back({a,b,c});
	}
	vector<ll> dp(n+1,0);
	dp[0] = 1;
	for(int i = 0; i <= n; ++i){
		if(dp[i] != 0){
			for(int j = i+1; j <= min(2050+i,n); ++j){
				if(abs(v[j][1]-v[i][1])+abs(v[j][2]-v[i][2]) <= v[j][0] - v[i][0])dp[j] = max(dp[j],dp[i]+1);
			}
		}
		if(i)dp[i] = max(dp[i],dp[i-1]);
	}
	cout << dp[n]-1 << '\n';
}