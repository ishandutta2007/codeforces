#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 1e9 + 7;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return (x * x) % md;
	} else {
		return (((x * x) % md) * n) % md;
	}
}

ll n , k = 0 , ans = 0 , d[3] , p[3];
string s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 0 ; i < 3 ; i++){
		d[i] = 0;
		p[i] = 0;
	}
	cin>>n>>s;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'a'){
			d[0]++;
		} else if(s[i] == 'c'){
			d[1]++;
		} else if(s[i] == '?') {
			d[2]++;
			k++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'a'){
			d[0]--;
		} else if(s[i] == 'c'){
			d[1]--;
		} else if(s[i] == '?') {
			d[2]--;
		}
		ll h = k;
		if(s[i] == 'b'){
			ans += ((p[0] * d[1]) % md) * tav(3 , h);
			ans %= md; h--;
			ans += (((p[2] * d[1] % md) + (p[0] * d[2] % md)) % md) * tav(3 , h);
			ans %= md; h--;
			ans += ((p[2] * d[2]) % md) * tav(3 , h);
		} else if(s[i] == '?'){
			h--;
			ans += ((p[0] * d[1]) % md) * tav(3 , h);
			ans %= md; h--;
			ans += (((p[2] * d[1] % md) + (p[0] * d[2] % md)) % md) * tav(3 , h);
			ans %= md; h--;
			ans += ((p[2] * d[2]) % md) * tav(3 , h);
			p[2]++;
		} else if(s[i] == 'a'){
			p[0]++;
		} else {
			p[1]++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}