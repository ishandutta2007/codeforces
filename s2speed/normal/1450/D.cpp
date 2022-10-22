#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 3e5 + 20;
 
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

vector<ll> v[MAX_N];

void solve(){
	bool one = true;
	string ans;
	ans.clear();
	ll n , k;
	cin>>n; k = n - 1;
	for(int i = 0 ; i < n ; i++){
		v[i].clear();
	}
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		v[h].push_back(i);
	}
	for(int i = 0 ; i < n ; i++){
		if(v[i].size() == 0){
			one = false;
			break;
		}
	}
	ll l = 0 , r = n - 1;
	for(int i = 0 ; i < n - 1 ; i++){
		if(v[i].size() == 0){
			k = i;
			break;
		}
		if(v[i].size() > 1){
			k = i + 1;
			break;
		}
		if(v[i][0] != l && v[i][0] != r){
			k = i + 1;
			break;
		}
		if(v[i][0] == l){
			l++;
		} else {
			r--;
		}
	}
	for(int i = 0 ; i < k ; i++){
		ans += '1';
	}
	for(int i = k ; i < n - 1 ; i++){
		ans += '0';
	}
	ans += '0' + one;
	reverse(ans.begin() , ans.end());
	cout<<ans<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}