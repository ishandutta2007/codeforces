#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<vector<ll>> v(2,vector<ll> (n));
	ll su = 0;
	for(auto &x : v)for(auto &y : x)cin >> y;
	vector<ll> f1 = {v[0][n-1]}, f2 = {v[0][n-1]}, s1 = {v[1][n-1]}, s2 = {v[1][n-1]};
	for(int i = n-2; ~i; --i){
		f1.push_back(max({v[0][i]+n-i-1,f1.back(),v[0][i+1]+n-i-1}));
		f2.push_back(max(v[0][i],f2.back()+1));
		s1.push_back(max({v[1][i]+n-i-1,s1.back(),v[1][i+1]+n-i-1}));
		s2.push_back(max(v[1][i],s2.back()+1));
	}
	reverse(f1.begin(),f1.end());
	reverse(f2.begin(),f2.end());
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());

	ll ans = (1ll<<60);
	ll cu = 0;
	for(int i = 0; i < n; ++i){
		if(i&1){
			ans = min(ans,max({s1[i]+n-i,f2[i]+1,cu+2*(n-i)-1}));
			cu++;
			cu = max(cu,v[0][i]+1);
			cu++;
			if(i != n-1)cu = max(cu,v[0][i+1]+1);
		}
		else{
			ans = min(ans,max({f1[i]+n-i,s2[i]+1,cu+2*(n-i)-1}));
			cu++;
			cu = max(cu,v[1][i]+1);
			cu++;
			if(i != n-1)cu = max(cu,v[1][i+1]+1);
		}
	}
	cout << ans << '\n';
}

int main(){
	int t; cin >> t; while(t--){
		solve();
	}
}