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

stack<ll> st;

void solve(){
	ll n , ans = 0;
	string s;
	cin>>s; n = s.size();
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'A'){
			st.push(0);
		} else {
			if(st.size() > 0){
				st.pop();
			} else {
				st.push(1);
			}
		}
	}
	while(st.size() > 0){
		st.pop();
		ans++;
	}
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