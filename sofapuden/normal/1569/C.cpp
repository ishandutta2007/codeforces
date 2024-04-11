#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 998244353;

ll inv(ll x){
	ll ret = 1;
	ll b = M-2;
	while(b){
		if(b&1){
			ret*=x;
			ret%=M;
		}
		x*=x;
		x%=M;
		b>>=1;
	}
	return ret;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		int mx = 0;
		map<int,int> Ma;
		for(int i = 0; i < n; ++i){
			Ma[v[i]]++;
			mx = max(mx,v[i]);
		}
		ll ans = 1;
		for(int i = 2; i <= n; ++i){
			ans*=i;
			ans%=M;
		}
		if(Ma[mx] == 1){
			
			ans*=inv(Ma[mx-1]+1);
			ans=ans%M;
			ans*=Ma[mx-1];
			ans=ans%M;
		}
		cout << ans << '\n';
	}

}