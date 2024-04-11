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

void solve(){
	char c[2];
	ll n , cnt = 0 , m = 0 , h = 0;
	string s;
	cin>>n>>s;
	c[0] = '0';
	c[1] = '1';
	for(int i = 0 ; i < n ; i++){
		if(s[i] != c[i % 2]){
			cnt++;
		} else {
			if(cnt != 0){
				m++;
				cnt = 0;
			}
		}
	}
	if(cnt != 0){
		m++;
		cnt = 0;
	}
	c[0] = '1';
	c[1] = '0';
	for(int i = 0 ; i < n ; i++){
		if(s[i] != c[i % 2]){
			cnt++;
		} else {
			if(cnt != 0){
				h++;
				cnt = 0;
			}
		}
	}
	if(cnt != 0){
		h++;
		cnt = 0;
	}
	cout<<min(m , h)<<"\n";
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