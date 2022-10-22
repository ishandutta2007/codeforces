#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

ll dp[MAX_N] , ma[MAX_N] , mi[MAX_N];
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , a , b , c , ans = -4e18;
	cin>>n>>a>>b>>c;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	dp[0] = 1ll * v[0] * (a + b);
	ma[0] = v[0];
	mi[0] = v[0];
	for(int i = 1 ; i < n ; i++){
		ma[i] = max(v[i] , ma[i - 1]);
		mi[i] = min(v[i] , mi[i - 1]);
		dp[i] = max(dp[i - 1] , 1ll * (a + b) * v[i]);
		if(a > 0){
			dp[i] = max(dp[i] , 1ll * b * v[i] + 1ll * ma[i - 1] * a);
		} else {
			dp[i] = max(dp[i] , 1ll * b * v[i] + 1ll * mi[i - 1] * a);
		}
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		ans = max(ans , 1ll * c * v[i] + dp[i]);
	}
	cout<<ans<<'\n';
	return 0;
}