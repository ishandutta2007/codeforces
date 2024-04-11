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

const ll maxn = 1.1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

bitset<maxn> mark;
vector<ll> v;
vector<pll> qu[maxn];
ll ans[maxn] , a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < q ; i++){
		ll j , k;
		cin>>j>>k; j--;
		qu[j].push_back({k , i});
	}
	ll cur = 1;
	v.push_back(0); mark[0] = true;
	for(ll i = 0 ; i < n ; i++){
		if(!mark[a[i]]){
			ll vs = sze(v);
			for(ll j = 0 ; j < vs ; j++){
				ll h = v[j] ^ a[i];
				v.push_back(h);
				mark[h] = true;
			}
		} else {
			cur <<= 1;
			cur -= (cur >= md) * md;
		}
		for(auto p : qu[i]){
			ll k = p.first , j = p.second;
			ans[j] = mark[k] * cur;
		}
	}
	for(ll i = 0 ; i < q ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}