#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

vector<ll> v;

void solve(){
	ll k;
	cin>>k;
	if(k == 1){
		cout<<"1 1\n";
		return;
	}
	ll h = lower_bound(all(v) , k) - v.begin() , o = k - h * h;
	if(o <= h + 1){
		cout<<o<<' '<<h + 1<<'\n';
		return;
	}
	o -= h;
	cout<<h + 1<<' '<<h + 2 - o<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 1 ; i * i < 1e9 ; i++){
		v.push_back(i * i);
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}