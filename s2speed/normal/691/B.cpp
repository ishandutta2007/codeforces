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
	
	string s;
	int n;
	cin>>s; n = s.size();
	int x = 0 , y = n - 1;
	while(x <= y){
		bool ch = false;
		ch |= (s[x] == 'A' && s[y] == 'A');
		ch |= (s[x] == 'b' && s[y] == 'd');
		ch |= (s[x] == 'd' && s[y] == 'b');
		ch |= (s[x] == 'H' && s[y] == 'H');
		ch |= (s[x] == 'I' && s[y] == 'I');
		ch |= (s[x] == 'M' && s[y] == 'M');
		ch |= (s[x] == 'O' && s[y] == 'O');
		ch |= (s[x] == 'o' && s[y] == 'o');
		ch |= (s[x] == 'p' && s[y] == 'q');
		ch |= (s[x] == 'q' && s[y] == 'p');
		ch |= (s[x] == 'T' && s[y] == 'T');
		ch |= (s[x] == 'U' && s[y] == 'U');
		ch |= (s[x] == 'V' && s[y] == 'V');
		ch |= (s[x] == 'v' && s[y] == 'v');
		ch |= (s[x] == 'W' && s[y] == 'W');
		ch |= (s[x] == 'w' && s[y] == 'w');
		ch |= (s[x] == 'X' && s[y] == 'X');
		ch |= (s[x] == 'x' && s[y] == 'x');
		ch |= (s[x] == 'Y' && s[y] == 'Y');
		if(!ch){
			cout<<"NIE\n";
			return 0;
		}
		x++;
		y--;
	}
	cout<<"TAK\n";
	return 0;
}

/*
*/