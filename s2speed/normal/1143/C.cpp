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

ll p[maxn] , a[maxn] , c[maxn];
vector<ll> adj[maxn] , v;

void cDFS(ll r){
	c[r] = 0;
	for(auto i : adj[r]){
		cDFS(i);
		c[r] |= a[i];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , r;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>p[i]>>a[i]; a[i] ^= 1;
		if(p[i] == -1){
			r = i;
		} else {
			p[i]--;
			adj[p[i]].push_back(i);
		}
	}
	cDFS(r);
	for(ll i = 0 ; i < n ; i++){
		if(!a[i] && !c[i]){
			v.push_back(i + 1);
		}
	}
	if(v.empty()){
		cout<<"-1\n";
		return 0;
	}
	for(auto i : v){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}