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

ll a[maxn] , f[maxn] , g[maxn] , k[maxn] , pg[maxn] , pk[maxn] , up[maxn] , lo[maxn];

ll ps(ll r , ll l , bool k){
	if(k){
		return pk[r - 1] - (l ? pk[l - 1] : 0);
	}
	return pg[r - 1] - (l ? pg[l - 1] : 0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; f[i] = max(0ll , i - a[i] + 1);
	}
	f[n] = f[n + 1] = n;
	ll cur = 0 , cur2 = 0;
	for(ll i = 0 ; i < n + 2 ; i++){
		ll o = min(f[i] , cur);
		while(cur2 < o){
			k[cur2++] = i;
		}
		lo[i] = cur;
		while(cur < f[i]){
			g[cur++] = i;
		}
		up[i] = cur;
	}
	pg[0] = g[0]; pk[0] = k[0];
	for(ll i = 1 ; i < n ; i++){
		pg[i] = pg[i - 1] + g[i];
		pk[i] = pk[i - 1] + k[i];
	}
	ll q;
	cin>>q;
	cur = 0;
	for(ll i = 0 ; i < n ; i++){
		cur += g[i] - i;
	}
	for(ll e = 0 ; e < q ; e++){
		ll i , t;
		cin>>i>>t; i--;
		ll y = max(0ll , i - t + 1) , x = f[i];
		if(x == y){
			cout<<cur<<'\n';
			continue;
		}
		if(x < y){
			if(up[i] > y){
				cout<<cur<<'\n';
				continue;
			}
			ll h = (y - up[i]) * i - ps(y , up[i] , false);
			cout<<cur + h<<'\n';
		} else {
			if(lo[i] >= x){
				cout<<cur<<'\n';
				continue;
			}
			ll o = max(lo[i] , y);
			ll h = ps(x , o , true) - ps(x , o , false);
			cout<<cur + h<<'\n';
		}
	}
	return 0;
}

/*
4
2 4 1 4
1
3 3
*/