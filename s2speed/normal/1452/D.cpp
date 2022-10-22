#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20 , md = 998244353;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x % md;
	} else {
		return x * x % md * n % md;
	}
}	

ll f[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , q;
	cin>>n;
	f[1] = 1;
	f[2] = 1;
	q = tav(2 , n);
	q = tav(q , md - 2);
	for(int i = 3 ; i <= n ; i++){
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= md;
	}
	q *= f[n];
	q %= md;
	cout<<q<<"\n";
	return 0;
}