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
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 2e15;

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

struct point {
	db x , y;
};

ll disq(point a , point b){
	if(a.x == inf || b.x == inf) return inf;
	db res = 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
	return res;
}

ll n;
db a[MAXN] , ps[MAXN];
vector<point> v , g , u , b;
point INF = {inf , inf};

ll solve(ll l , ll r){
	if(r - l == 1) return inf;
	ll m = (r + l) / 2 , d = min(solve(l , m) , solve(m , r));
	db q = sqrt(d) , p = m + q - 0.5;
	for(ll i = m ; i < r ; i++){
		if(v[i].x < p){
			g.push_back(v[i]);
		}
	}
	p = m - 0.5 - q;
	for(ll i = l ; i < m ; i++){
		if(v[i].x > p){
			u.push_back(v[i]);
		}
	}
	g.push_back(INF); u.push_back(INF);
	ll lx = 0 , rx = 0 , ly = 0 , ry = 0 , gs = g.size() , us = u.size() , res = d;
	while(rx < gs - 1 || ry < us - 1){
		if(rx == gs){
			while(g[lx].y < u[ry].y - q){
				lx++;
			}
			for(ll i = lx ; i < rx ; i++){
				res = min(res , disq(g[i] , u[ry]));
			}
			ry++;
			continue;
		}
		if(ry == us){
			while(u[ly].y < g[rx].y - q){
				ly++;
			}
			for(ll i = ly ; i < ry ; i++){
				res = min(res , disq(u[i] , g[rx]));
			}
			rx++;
			continue;
		}
		if(g[rx].y < u[ry].y){
			while(u[ly].y < g[rx].y - q){
				ly++;
			}
			for(ll i = ly ; i < ry ; i++){
				res = min(res , disq(u[i] , g[rx]));
			}
			rx++;
			continue;
		}
		while(g[lx].y < u[ry].y - q){
			lx++;
		}
		for(ll i = lx ; i < rx ; i++){
			res = min(res , disq(g[i] , u[ry]));
		}
		ry++;
	}
	g.clear(); u.clear(); b.clear();
	ll x = l , y = m;
	while(x < m || y < r){
		if(x == m){
			b.push_back(v[y++]);
			continue;
		}
		if(y == r){
			b.push_back(v[x++]);
			continue;
		}
		if(v[x].y < v[y].y){
			b.push_back(v[x++]);
		} else {
			b.push_back(v[y++]);
		}
	}
	for(ll i = l ; i < r ; i++){
		v[i] = b[i - l];
	}
	return res;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>a[0]; ps[0] = a[0];
	for(ll i = 1 ; i < n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for(db i = 0 ; i < n ; i++){
		point h = {i , ps[(ll)i]};
		v.push_back(h);
	}
	cout<<solve(0 , n)<<'\n';
	return 0;
}