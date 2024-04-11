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
	ll n , vs = 0 , x = 0 , y = 0 , ans = 0;
	string s;
	cin>>n>>s;
	v.push_back(1);
	for(int i = 1 ; i < n ; i++){
		if(s[i] == s[i - 1]){
			v[vs]++;
		} else {
			v.push_back(1);
			vs++;
		}
	}
	vs++;
	for(int i = 0 ; i < vs ; i++){
		while(v[y] <= 1 && y < vs){
			y++;
		}
		if(y == vs){
			break;
		}
		v[y]--;
		v[x] = 0;
		x++;
		ans++;
	}
	ans += (vs - x + 1) / 2;
	cout<<ans<<"\n";
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