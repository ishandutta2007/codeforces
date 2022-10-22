#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
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

set<int> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a , b , c;
	cin>>a>>b>>c;
	s.insert(a);
	for(int i = 1 ; i <= b ; i++){
		a *= 10;
		int h = a / b;
		if(h == c){
			cout<<i<<'\n';
			return 0;
		}
		a %= b;
		if(s.count(a)){
			cout<<"-1\n";
			return 0;
		}
		s.insert(a);
	}
	return 0;
}