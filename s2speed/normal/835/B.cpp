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

ll coun[10];

void solve(){
	for(int i = 0 ; i < 10 ; i++){
		coun[i] = 0;
	}
	ll k , sum = 0 , counter = 0;
	string s;
	cin>>k>>s;
	ll ss = s.size();
	for(int i = 0 ; i < ss ; i++){
		coun[s[i] - '0']++;
		sum += s[i] - '0';
	}
	if(sum >= k){
		cout<<"0\n";
		return;
	}
	for(int i = 0 ; i < 10 ; i++){
		ll h = k - sum , q = (9 - i);
		if(h <= coun[i] * q){
			counter += (h + q - 1) / q;
			cout<<counter<<"\n";
			return;
		} else {
			counter += coun[i];
			sum += coun[i] * q;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}