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

const ll MAX_N = 3e5 + 20 , md = 1e9 + 7 , inf = 1e17;
 
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

ll a[MAX_N];
bool c[MAX_N];

bool hv(ll a , ll b , ll c){
	if(b > a && b > c){
		return true;
	}
	if(b < a && b < c){
		return true;
	}
	return false;
}

void solve(){
	ll n , sum = 0 , m = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		c[i] = false;
	}
	for(int i = 1 ; i < n - 1 ; i++){
		if(a[i] < a[i + 1] && a[i] < a[i - 1]){
			c[i] = true;
		}
		if(a[i] > a[i - 1] && a[i] > a[i + 1]){
			c[i] = true;
		}
		sum += c[i];
	}
	for(int i = 0 ; i < n ; i++){
		ll q , o = 0 , k = 0 , u;
		o += c[i];
		if(i > 0){
			o += c[i - 1];
		}
		if(i < n - 1){
			o += c[i + 1];
		}
		u = o;
		if(i > 0){
			q = a[i - 1];
			if(i > 1){
				k += hv(a[i - 2] , a[i - 1] , q);
			}
			if(i < n - 1){
				k += hv(a[i - 1] , q , a[i + 1]);
			}
			if(i < n - 2){
				k += hv(q , a[i + 1] , a[i + 2]);
			}
			u = min(u , k);
		}
		k = 0;
		if(i < n - 1){
			q = a[i + 1];
			if(i > 1){
				k += hv(a[i - 2] , a[i - 1] , q);
			}
			if(i > 0){
				k += hv(a[i - 1] , q , a[i + 1]);
			}
			if(i < n - 2){
				k += hv(q , a[i + 1] , a[i + 2]);
			}
			u = min(u , k);
		}
		m = max(m , o - u);
	}
	cout<<sum - m<<'\n';
}

int main(){ // check MAX_N
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

/*

*/