#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 100 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

ll a[MAX_N][MAX_N] , res[MAX_N][MAX_N] , has[MAX_N][MAX_N] , x[MAX_N] , n;

void mul(ll b[MAX_N][MAX_N] , ll c[MAX_N][MAX_N]){
	memset(has , 0 , sizeof(has));
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			for(ll q = 0 ; q < n ; q++){
				has[i][j] += 1ll * b[i][q] * c[q][j] % md;
				has[i][j] %= md;
			}
		}
	}
	return;
}

void tav(ll k){
	memset(res , 0 , sizeof(res));
	for(ll i = 0 ; i < n ; i++){
		res[i][i] = 1;
	}
	while(k > 0){
		if(k & 1){
			mul(a , res);
			memcpy(res , has , sizeof(has));
		}
		mul(a , a);
		memcpy(a , has , sizeof(has));
		k /= 2;
	}
	return;
}

ll bpc(ll p){
	ll o = 1 , cnt = 0;
	for(int i = 0 ; i < 63 ; i++){
		if(o & p) cnt++;
		o *= 2;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll k;
	cin>>n>>k; k--;
	memset(a , 0 , sizeof(a));
	for(ll i = 0 ; i < n ; i++){
		cin>>x[i];
	}
	for(ll i = 0 ; i < n ; i++){
		a[i][i] = 1;
		for(ll j = i + 1 ; j < n ; j++){
			ll h = x[i]; h ^= x[j];
			if(bpc(h) % 3 == 0){
				a[i][j] = 1;
				a[j][i] = 1;
			}
		}
	}
	ll ans = 0;
	tav(k);
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			ans += res[i][j]; ans %= md;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*
576460752303423488
*/