#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 21;

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

ll fact[MAX_N];

void fact_build(){
	fact[0] = 1;
	for(int i = 1 ; i < MAX_N ; i++){
		fact[i] = fact[i - 1] * i;
	}
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	fact_build();
	ll n;
	cin>>n;
	ll ans = fact[n];
	ans /= fact[n / 2];
	ans /= fact[n / 2];
	ans *= fact[n / 2 - 1];
	ans *= fact[n / 2 - 1];
	ans /= 2;
	cout<<ans<<"\n";
	return 0;
}