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
	ll n , h;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v.push_back(h);
	}
	sort(v.begin() , v.end());
	cout<<(n - 1) / 2<<"\n";
	ll x = n - 1 , y = 0;
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == 0){
			cout<<v[x]<<" ";
			x--;
		} else {
			cout<<v[y]<<" ";
			y++;
		}
	}
	cout<<"\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}