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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e18;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll ps[MAXN] , a[MAXN] , tx[MAXN] , val[MAXN];
set<pll> used , nusd;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , w , k , t , x = 0 , ans = 0;
	cin>>n>>w>>k; t = k;
	tx[0] = 0; a[0] = 0; ps[0] = 0; val[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>val[i];
		ps[i] = ps[i - 1] + val[i];
	}
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		tx[i] = tx[i - 1] + a[i];
	}
	tx[n + 1] = inf; a[n + 1] = 0;
	for(ll i = 1 ; i <= n ; i++){
		pll q = {a[i - 1] / 2 , i - 1};
		if(used.count(q)){
			t -= q.first;
			if(!nusd.empty()){
				auto it = nusd.end(); it--;
				pll p = *it;
				nusd.erase(p);
				used.insert(p);
				t += p.first;
			}
		}
		used.erase(q);
		nusd.erase(q);
		t += a[i - 1];
		while(tx[x + 1] - a[x + 1] / 2 <= t){
			x++;
			pll v = {a[x] / 2 , x};
			if(used.size() < w){
				t += a[x] / 2;
				used.insert(v);
				continue;
			}
			auto it = used.begin();
			pll p = *it;
			if(v > p){
				t -= a[p.second] / 2;
				t += a[x] / 2;
				used.erase(p);
				used.insert(v);
				nusd.insert(p);
			} else {
				nusd.insert(v);
			}
		}
		ll e = x - (t < tx[x]) , o = ps[e] - ps[i - 1];
		ans = max(ans , o);
	}
	cout<<ans<<'\n';
	return 0;
}

/*
3 1 9
8 8 8
5 3 4
*/