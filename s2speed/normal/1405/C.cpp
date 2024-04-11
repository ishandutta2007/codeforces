#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

vector<string> v;

void solve(){
	ll n , k , counter[2] , ans[2]; ans[0] = 0; ans[1] = 0;
	string s;
	cin>>n>>k>>s;
	v.resize(k);
	for(int i = 0 ; i < n ; i++){
		v[i % k] += s[i];
	}
	for(int i = 0 ; i < k ; i++){
		ll o = v[i].size();
		counter[0] = 0; counter[1] = 0;
		for(int j = 0 ; j < o ; j++){
			if(v[i][j] == '0'){
				counter[0]++;
			} else if(v[i][j] == '1'){
				counter[1]++;
			}
		}
		if(counter[0] > 0 && counter[1] > 0){
			cout<<"NO\n";
			v.clear();
			return;
		} else if(counter[0] > 0){
			ans[0]++;
		} else if(counter[1] > 0){
			ans[1]++;
		}
	}
	if(ans[0] <= k / 2 && ans[1] <= k / 2){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	v.clear();
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}