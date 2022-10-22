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

const ll MAXN = 2e5 + 15 , md = 2000000357 , p = 31 , inf = 1e15;

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

map<ll , ll> t;
set<ll> pal;
vector<ll> khali;
vector< vector<ll> > h , r;
string s[MAXN];
ll n , k , x = 1 , val[MAXN] , u[MAXN];
vector<pll> pc;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	h.push_back(khali); r.push_back(khali);
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		cin>>s[i]>>val[i];
	}
	for(ll j = 0 ; j < n ; j++){
		string o = s[j];
		reverse(all(o));
		ll sh = 0 , oh = 0 , e = 1;
		for(ll i = 0 ; i < k ; i++){
			ll as = s[j][i] - 'a' + 1 , os = o[i] - 'a' + 1;
			as *= e; os *= e;
			as %= md; os %= md;
			sh += as; oh += os;
			e *= p; e %= md;
		}
		sh %= md; oh %= md;
		if(!t.count(sh)){
			u[x] = sh;
			t[sh] = x++;
			h.push_back(khali); r.push_back(khali);
		}
		if(!t.count(oh)){
			u[x] = oh;
			t[oh] = x++;
			h.push_back(khali); r.push_back(khali);
		}
		if(sh == oh){
			pal.insert(sh);
			h[t[sh]].push_back(val[j]);
		} else {
			h[t[sh]].push_back(val[j]);
			r[t[oh]].push_back(val[j]);
		}
	}
	ll ans = 0 , np = 0 , mt = 0;
	for(ll i = 1 ; i < x ; i++){
		sort(all(h[i]) , greater<ll>()); sort(all(r[i]) , greater<ll>());
		if(pal.count(u[i])){
			ll hs = h[i].size();
			for(ll j = 0 ; j < hs - 1 ; j += 2){
				if(h[i][j + 1] >= 0){
					ans += h[i][j] + h[i][j + 1];
				} else {
					if(h[i][j] + h[i][j + 1] <= 0){
						mt = max(mt , h[i][j]);
						break;
					}
					pc.push_back({h[i][j] , h[i][j + 1]});
					break;
				}
			}
			if(hs % 2){
				mt = max(mt , h[i].back());
			}
			continue;
		}
		ll o = min(h[i].size() , r[i].size());
		for(ll j = 0 ; j < o ; j++){
			if(h[i][j] + r[i][j] <= 0){
				break;
			}
			np += h[i][j] + r[i][j];
		}
	}
	np >>= 1;
	ans += np;
	ll bt = 0 , st = 0;
	for(auto q : pc){
		bt = max(bt , -q.second);
		st += q.first + q.second;
	}
	ans += st;
	ans += max(mt , bt);
	cout<<ans<<'\n';
	return 0;
}

/*

*/