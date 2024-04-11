#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 1e5 + 20 , md = 1e9 + 7;
 
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

vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a , b , c;
	cin>>a>>b>>c;
	if(b > c){
		swap(b , c);
	}
	if(a > b){
		swap(a , b);
	}
	if(b > c){
		swap(b , c);
	}
	if(2 * (a + b) >= c){
		cout<<(a + b + c) / 3<<'\n';
	} else {
		cout<<a + b<<'\n';
	}
	return 0;
}