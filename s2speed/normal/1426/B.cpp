#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(){
	bool ch = false;
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		ll a , b , c , d;
		cin>>a>>b>>c>>d;
		if(b == c){
			ch = true;
		}
	}
	if(ch == true && m % 2 == 0){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return;
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