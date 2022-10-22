#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define size(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;
 
const ll maxn = 2.5e5 + 16 , md = 998244353 , inf = 2e18;
 
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

vector<pair<ll , bool>> adj[maxn];
vector<ll> rc[maxn];
ll c[maxn] , x = 0;
bitset<maxn> mark;

void cDFS(ll r){
	c[r] = x;
	rc[x].push_back(r);
	mark[r] = true;
	for(auto p : adj[r]){
		ll i = p.first;
		if(mark[i]) continue;
		cDFS(i);
	}
	return;
}

bool fix = false , ans = true;
db h , a[maxn];
vector<ll> v , u;
pair<ll , bool> dis[maxn];

void aDFS(ll r){
	mark[r] = true;
	for(auto p : adj[r]){
		ll i = p.first , k = p.second;
		if(mark[i]){
			ll a = dis[i].first + dis[r].first;
			if(dis[i].second ^ dis[r].second){
				ans &= (a == 1 + k);
			} else {
				a = 1 + k - a;
				if(!dis[i].second) a = -a;
				db o = (long double)1 * a / 2;
				if(fix && o != h){
					ans = false;
				}
				fix = true;
				h = o;
			}
			if(!ans) return;
			continue;
		}
		dis[i].second = 1 - dis[r].second;
		dis[i].first = 1 + k - dis[r].first;
		aDFS(i);
		if(!ans) return;
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , k;
		cin>>v>>u>>k; v--; u--; k--;
		adj[v].push_back({u , k}); adj[u].push_back({v , k});
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		cDFS(i);
		x++;
	}
	mark.reset();
	for(ll i = 0 ; i < n ; i++){
		if(rc[i].empty()) break;
		ll r = rc[i][0];
		dis[r] = {0 , 1};
		aDFS(r);
		if(!ans){
			cout<<"NO\n";
			return 0;
		}
		if(fix){
			fix = false;
			for(auto j : rc[i]){
				a[j] = dis[j].first + (long double)(-1 + 2 * dis[j].second) * h;
			}
			continue;
		}
		v.clear(); u.clear();
		for(auto j : rc[i]){
			if(dis[j].second){
				v.push_back(dis[j].first);
			} else {
				u.push_back(dis[j].first);
			}
		}
		sort(all(v));
		sort(all(u) , greater<ll>());
		ll x = 0 , y = 0 , vs = size(v) , us = size(u) , st = 2 * (vs + us) , cur = 0 , ind = -1 , m = inf;
		v.push_back(inf); u.push_back(-inf);
		for(auto j : rc[i]){
			cur += abs(dis[j].first + (-1 + 2 * dis[j].second) * st);
		}
		for(ll z = st ; z >= -st ; z--){
			if(cur < m){
				m = cur;
				ind = z;
			}
			while(v[x] == -z){
				x++;
			}
			while(u[y] == z){
				y++;
			}
			cur += x; cur += y;
			cur -= vs - x; cur -= us - y;
		}
		for(auto j : rc[i]){
			a[j] = dis[j].first + (long double)(-1 + 2 * dis[j].second) * ind;
		}
	}
	cout<<fixed<<setprecision(7)<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return 0;
}