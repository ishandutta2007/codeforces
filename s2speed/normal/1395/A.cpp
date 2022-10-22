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

const ll z = 0;

vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		bool ans = false;
		ll a , b , c , d , counter[2];
		counter[0] = 0; counter[1] = 0;
		cin>>a>>b>>c>>d;
		counter[a % 2]++; counter[b % 2]++; counter[c % 2]++; counter[d % 2]++;
		v.push_back(a); v.push_back(b); v.push_back(c);
		sort(v.begin() , v.end());
		if(counter[0] != counter[1] && counter[1] < counter[0]){
			ans = true;
		} else if(counter[0] != counter[1] && v[0] > 0){
			ans = true;
		}
		if(ans == true){
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
		v.clear();
	}
	return 0;
}