#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

void solve(){
	vector<int> v(3);
	for(int i = 0 ; i < 3 ; i++){
		cin>>v[i];
	}
	sort(v.begin() , v.end());
	if((v[0] + v[1] + v[2]) % 9 != 0){
		cout<<"NO\n";
		return;
	}
	int h = v[2] + v[1];
	h -= 2 * v[0];
	if(h <= 6 * v[0]){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}