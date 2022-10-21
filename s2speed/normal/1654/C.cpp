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

multiset<ll , greater<ll>> a , v;

void solve(){
	v.clear(); a.clear();
	ll n , sum = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; sum += h;
		a.insert(h);
	}
	v.insert(sum);
	ll y = 0;
	while(!v.empty()){
		ll b = *v.begin(); v.erase(v.begin());
//		cout<<b<<' ';
		if(b < *a.begin()){
			y = -1;
			break;
		}
		if(a.count(b)){
			y++;
			a.erase(a.find(b));
			continue;
		}
		v.insert((b + 1) >> 1); v.insert(b >> 1);
	}
	cout<<(y == n ? "YES\n" : "NO\n");
	return;
}

/*
1
10
1 2 4 7 1 1 1 1 7 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}