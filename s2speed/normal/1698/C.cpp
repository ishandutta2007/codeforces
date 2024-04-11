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

ll a[maxn];
vector<ll> v;
set<ll> s;

void solve(){
	v.clear(); s.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] != 0) v.push_back(a[i]);
	}
	ll vs = sze(v);
	if(vs >= 5){
		cout<<"NO\n";
		return;
	}
	if(vs < n){
		v.push_back(0); vs++;
	}
	for(auto i : v){
		s.insert(i);
	}
	for(ll i = 0 ; i < vs ; i++){
		for(ll j = i + 1 ; j < vs ; j++){
			for(ll k = j + 1 ; k < vs ; k++){
				if(s.count(v[i] + v[j] + v[k]) == 0){
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}