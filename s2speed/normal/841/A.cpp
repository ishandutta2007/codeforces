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

ll a[26];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 0 ; i < 26 ; i++){
		a[i] = 0;
	}
	bool ans = true;
	ll n , k;
	string s;
	cin>>n>>k>>s;
	for(int i = 0 ; i < n ; i++){
		a[s[i] - 'a']++;
	}
	for(int i = 0 ; i < 26 ; i++){
		if(a[i] > k){
			ans = false;
			break;
		}
	}
	if(ans){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return 0;
}