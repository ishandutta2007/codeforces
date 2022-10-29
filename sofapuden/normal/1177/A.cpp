#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll x; cin >> x;
	ll cn = 0;
	string s;
	while(x>0){
		x-=(ll)(9ll*pow(10ll,cn)*(cn+1));
		cn++;
	}
	cn--;
	x+=(ll)(9ll*pow(10ll,cn)*(cn+1));
	x--;
	ll ori = cn;
	s+=to_string((ll)(x/((cn+1)*pow(10ll,cn))+1ll));
	x%=(ll)((cn+1)*pow(10ll,cn));
	while(cn--){
		s+=to_string((ll)(x/((ori+1)*pow(10ll,cn))));
		x%=(ll)((ori+1)*(pow(10ll,cn)));
	}
	cout << s[x] << "\n";
}