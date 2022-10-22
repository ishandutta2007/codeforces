#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
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
	
	int n , a , l , r , h;
	cin>>n>>a>>l>>r;
	if(r == n && l == 1){
		cout<<"0\n";
		return 0;
	}
	if(r == n){
		cout<<abs(l - a) + 1<<'\n';
		return 0;
	}
	if(l == 1){
		cout<<abs(r - a) + 1<<'\n';
		return 0;
	}
	if(a <= l){
		cout<<r - a + 2<<'\n';
		return 0;
	}
	if(a >= r){
		cout<<a - l + 2<<'\n';
		return 0;
	}
	h = min(r - a , a - l);
	cout<<h + r - l + 2<<'\n';
	return 0;
}