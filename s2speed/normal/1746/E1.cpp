#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> v , u[4];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		v.push_back(i);
	}
	while(sze(v) > 3){
		for(ll j = 0 ; j < 4 ; j++) u[j].clear();
		ll vs = sze(v);
		for(ll i = 0 ; i < vs ; i++){
			u[i % 4].push_back(v[i]);
		}
		ll u0 = sze(u[0]) , u1 = sze(u[1]) , u2 = sze(u[2]);
		cout<<"? "<<u0 + u1<<' ';
		for(auto i : u[0]){
			cout<<i<<' ';
		}
		for(auto i : u[1]){
			cout<<i<<' ';
		}
		cout<<endl;
		cin>>s;
		ll a = (s[0] == 'Y') , b;
		cout<<"? "<<u0 + u2<<' ';
		for(auto i : u[0]){
			cout<<i<<' ';
		}
		for(auto i : u[2]){
			cout<<i<<' ';
		}
		cout<<endl;
		cin>>s;
		b = (s[0] == 'Y');
		ll k = b + (a << 1);
		v.clear();
		for(ll j = 0 ; j < 4 ; j++){
			if(j == k) continue;
			for(auto i : u[j]) v.push_back(i);
		}
	}
	if(sze(v) == 3){
		cout<<"? 2 "<<v[0]<<' '<<v[1]<<endl;
		cin>>s;
		ll a = (s[0] == 'Y') , b , c , d;
		if(a == 1){
			cout<<"? 2 "<<v[0]<<' '<<v[1]<<endl;
			cin>>s;
			b = (s[0] == 'Y');
			if(b == 1){
				v.pop_back();
			} else {
				cout<<"! "<<v[2]<<endl;
				cin>>s;
				if(s[1] == ')') return 0;
				cout<<"? 1 "<<v[0]<<endl;
				cin>>s;
				if(s[0] == 'Y'){
					cout<<"! "<<v[0]<<endl;
				} else {
					cout<<"! "<<v[1]<<endl;
				}
				return 0;
			}
		} else {
			cout<<"! "<<v[2]<<endl;
			cin>>s;
			if(s[1] == ')') return 0;
			cout<<"? 1 "<<v[0]<<endl;
			cin>>s;
			if(s[0] == 'Y'){
				cout<<"! "<<v[0]<<endl;
			} else {
				cout<<"! "<<v[1]<<endl;
			}
			return 0;
		}
	}
	if(sze(v) == 1){
		cout<<"! "<<v[0]<<endl;
		return 0;
	}
	if(sze(v) == 2){
		cout<<"! "<<v[0]<<endl;
		cin>>s;
		if(s[1] == ')') return 0;
		cout<<"! "<<v[1]<<endl;
		return 0;
	}
	return 0;
}