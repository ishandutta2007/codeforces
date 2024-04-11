#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll a , b , c , d;
		cin>>a>>b>>c>>d;
		c = max(a - c , c - 1);
		d = max(b - d , d - 1);
		cout<<c + d<<'\n';
	}
	return 0;
}