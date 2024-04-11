#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e3+5;

ll dp[mxN][mxN];
vector<ll> v;

ll fin(int l, int r){
	if(l < 0 || r >= v.size())return 1ll<<60;
	if(l == 0 && r == v.size()-1)return v[r]-v[l];
	if(dp[l][r])return dp[l][r];
	ll ret = v[r]-v[l];
	return dp[l][r] = ret+min(fin(l-1,r),fin(l,r+1));
}

int main(){
	memset(dp,0,sizeof dp);
	int n; cin >> n;
	v.resize(n);
	for(auto &x : v) cin >> x;
	sort(v.begin(),v.end());
	if(v[0] == v.back()){
		cout << "0\n";
		return 0;
	}
	ll ans = 1ll<<60;
	for(int i = 0; i < n; ++i){
		ans = min(ans,fin(i,i));
	}
	cout << ans << '\n';

}