#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

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

vector<ll> v;

void solve(){
	v.clear();
	bool st = false;
	ll n , k , ans = 0 , p = -1 , q = 0;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i = 0 ; i < n ; i++){
		if(q == 0 && s[i] == 'W'){
			p = 0;
			q++;
		} else if(s[i] == 'W'){
			if(p > 0){
				v.push_back(p);
			}
			p = 0;
			q++;
		} else {
			p++;
		}
		if(s[i] == 'W'){
			ans++;
			ans += st;
			st = true;
		} else {
			st = false;
		}
	}
	if(q == 0){
		ans = max(0LL , k * 2 - 1);
		cout<<ans<<"\n";
		return;
	}
	sort(v.begin() , v.end());
	ans += k * 2;
	ll vs = v.size();
	for(int i = 0 ; i < vs && k > 0 ; i++){
		k -= v[i];
		ans++;
	}
	if(k < 0){
		ans--;
	}
	cout<<min(ans , 2 * n - 1)<<"\n";
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