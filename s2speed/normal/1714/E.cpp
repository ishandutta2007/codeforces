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

string s;
ll a[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	bool f = true;
	for(ll i = 1 ; i < n ; i++){
		f &= (a[i] == a[0]);
	}
	if(f){
		cout<<"YES\n";
		return;
	}
	bool c = false;
	for(ll i = 0 ; i < n ; i++){
		a[i] += a[i] % 10;
		c |= (a[i] % 10 == 0);
	}
	if(c){
		f = true;
		for(ll i = 1 ; i < n ; i++){
			f &= (a[i] == a[0]);
		}
		cout<<(f ? "YES\n" : "NO\n");
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		while(a[i] % 10 != 6){
			a[i] += a[i] % 10;
		}
	}
	f = true;
	ll t = ((a[0] / 10) & 1);
	for(ll i = 1 ; i < n ; i++){
		f &= (((a[i] / 10) & 1) == t);
	}
	cout<<(f ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}