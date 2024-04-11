#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 27e5 + 15 , md = 1e9 + 7 , inf = 1e10;

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

ll tc[MAXN][2] , last = 0 , cnt[MAXN] , cur = 0;

void add(bitset<27> &h){
	ll v = 0;
	for(ll i = 26 ; i >= 0 ; i--){
		if(tc[v][h[i]] == -1){
			tc[v][h[i]] = ++last;
		}
		v = tc[v][h[i]];
		cnt[v]++;
	}
	return;
}

void del(bitset<27> &h){
	ll v = 0;
	for(ll i = 26 ; i >= 0 ; i--){
		v = tc[v][h[i]];
		cnt[v]--;
	}
	return;
}

ll ans(bitset<27> &h , bitset<27> &o){
	ll res = cur , v = 0;
	for(ll i = 26 ; i >= 0 ; i--){
		if(o[i]){
			v = tc[v][!h[i]];
		} else {
			ll u = tc[v][!h[i]];
			if(u != -1){
				res -= cnt[u];
			}
			v = tc[v][h[i]];
		}
		if(v == -1) break;
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(tc , -1 , sizeof(tc));
	memset(cnt , 0 , sizeof(cnt));
	ll q;
	cin>>q;
	bitset<27> h , o;
	while(q--){
		ll t , e;
		cin>>t;
		if(t == 1){
			cin>>e;
			h = e;
			add(h);
			cur++;
		}
		if(t == 2){
			cin>>e;
			h = e;
			del(h);
			cur--;
		}
		if(t == 3){
			cin>>e;
			h = e;
			cin>>e; e--;
			o = e;
			cout<<ans(h , o)<<'\n';
		}
	}
	return 0;
}

/*

*/