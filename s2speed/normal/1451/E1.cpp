#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 0;

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

vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//  0 = XOR, 1 = AND, 2 = OR	
	ll n , ab[3] , ac[3] , bc[3] , h = 1 , a , b , c , d , e;
	cin>>n;
	v.assign(n + 1 , 0);
	cout<<"XOR 1 2\n";
	cout.flush();
	cin>>ab[0];
	cout<<"XOR 1 3\n";
	cout.flush();
	cin>>ac[0];
	bc[0] = ac[0] ^ ab[0];
	cout<<"AND 1 2\n";
	cout.flush();
	cin>>ab[1];
	ab[2] = ab[0] | ab[1];
	cout<<"AND 1 3\n";
	cout.flush();
	cin>>ac[1];
	ac[2] = ac[0] | ac[1];
	cout<<"AND 2 3\n";
	cout.flush();
	cin>>bc[1];
	bc[2] = bc[0] | bc[1];
	for(int i = 0 ; i < 17 ; i++){
		a = ab[1] & h;
		b = ac[1] & h;
		c = bc[1] & h;
		d = ab[0] & h;
		e = ac[0] & h;
		if(a || b){
			v[1] += h;
		} else {
			if(d && e && !c){
				v[1] += h;
			}
		}
		h = h << 1;
		
	}
	v[2] = v[1] ^ ab[0];
	v[3] = v[1] ^ ac[0];
	for(int i = 4 ; i <= n ; i++){
		ll f;
		cout<<"XOR 1 "<<i<<"\n";
		cout.flush();
		cin>>f;
		v[i] = f ^ v[1];
	}
	cout<<"! ";
	for(int i = 1 ; i <= n ; i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	return 0;
}