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

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(all(v));
	for(int i = n - 1 ; i >= 0 ; i--){
		if(k % v[i] == 0){
			cout<<k / v[i]<<'\n';
			return 0;
		}
	}
	return 0;
}