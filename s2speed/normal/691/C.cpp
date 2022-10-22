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

string ist(int r){
	bool neg = false;
	string h;
	if(r < 0){
		neg = true;
		r -= 2 * r;
	}
	while(r > 0){
		h += '0' + r % 10;
		r /= 10;
	}
	if(neg) h += '-';
	reverse(all(h));
	return h;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s , h , r;
	int n , q = 1e8 , b , d;
	cin>>s; n = s.size();
	bool in = false;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '.'){
			d = i;
			in = true;
			break;
		}
	}
	if(!in){
		s += '.';
		d = n;
	}
	in = false;
	n = s.size();
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '.'){
		} else if(s[i] != '0'){
			q = i;
			h += s[i];
			break;
		}
	}
	for(int i = n - 1 ; i > q ; i--){
		if(s[i] == '.') continue;
		if(s[i] != '0'){
			if(!in){
				h += '.';
			}
			in = true;
		}
		if(in){
			r += s[i];
		}
	}
	reverse(all(r));
	h += r;
	b = d - q;
	b -= (b > 0);
	if(b != 0){
		h += 'E';
		h += ist(b);
	}
	cout<<h<<'\n';
	return 0;
}

/*
*/