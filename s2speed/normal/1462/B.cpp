#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 1e6 + 20 , md = 1e9 + 7;
 
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
	int n;
	string s;
	cin>>n>>s;
	if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'){
		cout<<"YES\n";
		return;
	}
	if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0'){
		cout<<"YES\n";
		return;
	}
	if(s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0'){
		cout<<"YES\n";
		return;
	}
	if(s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0'){
		cout<<"YES\n";
		return;
	}
	if(s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0'){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
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