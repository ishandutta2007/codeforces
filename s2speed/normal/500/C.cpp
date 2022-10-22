#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll a[maxn] , b[maxn] , c[maxn];
vector<ll> v , u;
vector<pll> w;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , 63 , sizeof(c));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i]; b[i]--;
		c[b[i]] = min(c[b[i]] , i);
	}
	for(ll i = 0 ; i < n ; i++){
		w.push_back({c[i] , i});
	}
	sort(all(w) , greater<pll>());
	for(ll i = 0 ; i < n ; i++){
		v.push_back(w[i].second);
	}
	ll ans = 0;
	for(ll i = 0 ; i < m ; i++){
		while(v.back() != b[i]){
			u.push_back(v.back());
			ans += a[v.back()];
			v.pop_back();
		}
		v.pop_back();
		while(!u.empty()){
			v.push_back(u.back());
			u.pop_back();
		}
		v.push_back(b[i]);
	}
	cout<<ans<<'\n';
	return 0;
}