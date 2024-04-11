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

const ll maxn = 1e3 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> v , u;

void solve(){
	v.clear();
	ll n;
	cin>>n;
	ll lm = (1 << n);
	for(ll i = 1 ; i <= lm ; i++){
		v.push_back(i);
	}
	while(sze(v) >= 4){
		u.clear();
		ll vs = sze(v);
		for(ll i = 0 ; i < vs ; i += 4){
			ll a = v[i] , b = v[i + 1] , c = v[i + 2] , d = v[i + 3];
			cout<<"? "<<a<<' '<<c<<endl;
			ll h; 
			cin>>h;
			if(h == 0){
				cout<<"? "<<b<<' '<<d<<endl;
				ll o;
				cin>>o;
				u.push_back((o == 1 ? b : d));
			} else if(h == 1){
				cout<<"? "<<a<<' '<<d<<endl;
				ll o;
				cin>>o;
				u.push_back((o == 1 ? a : d));
			} else {
				cout<<"? "<<c<<' '<<b<<endl;
				ll o;
				cin>>o;
				u.push_back((o == 1 ? c : b));
			}
		}
		v = u;
	}
	if(sze(v) == 2){
		cout<<"? "<<v[0]<<' '<<v[1]<<endl;
		ll h;
		cin>>h;
		cout<<"! "<<(h == 1 ? v[0] : v[1])<<endl;
		return;
	}
	cout<<"! "<<v[0]<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}