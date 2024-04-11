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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

vector<ll> v;
vector<pll> u;
// a = 12 b = 23 c = 31
void solve(){
	v.clear(); u.clear();
	ll n , a , b , c , o = 3 , g[] = {0 , 1 , 2 , 3};
	cin>>n>>a>>b>>c;
	if(b > a && b >= c){
		swap(b , a);
		swap(b , c);
		g[1] = 2; g[2] = 3; g[3] = 1;
	}
	if(c > a && c > b){
		swap(c , a);
		swap(b , c);
		g[1] = 3; g[2] = 1; g[3] = 2;
	}
	if(a + b < c || a + c < b || b + c < a){
		cout<<"NO\n";
		return;
	}
	if((a + b + c) & 1){
		cout<<"NO\n";
		return;
	}
	v.push_back(1);
	bool f = (b + c == a);
	for(ll i = 1 ; i < a ; i++){
		if(f && i == c){
			v.push_back(3);
		} else {
			v.push_back(++o);
		}
	}
	v.push_back(2);
	ll vs = sze(v);
	for(ll i = 1 ; i < vs ; i++){
		u.push_back({v[i - 1] , v[i]});
	}
	if(!f){
		ll k = ((b + c) - a) >> 1;
		ll j = c - k;
		if(j >= vs){
			cout<<"NO\n";
			return;
		}
		j = v[j];
		v.clear();
		v.push_back(j);
		for(ll i = 1 ; i < k ; i++){
			v.push_back(++o);
		}
		v.push_back(3);
		vs = sze(v);
		for(ll i = 1 ; i < vs ; i++){
			u.push_back({v[i - 1] , v[i]});
		}
	}
	if(o > n){
		cout<<"NO\n";
		return;
	}
	while(o < n){
		u.push_back({1 , ++o});
	}
	cout<<"YES\n";
	for(auto p : u){
		cout<<(p.first <= 3 ? g[p.first] : p.first)<<' '<<(p.second <= 3 ? g[p.second] : p.second)<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}