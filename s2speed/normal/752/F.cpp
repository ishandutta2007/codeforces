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

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e9;

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

vector<ll> adj[MAXN] , zr[MAXN];
bitset<MAXN> mark;
ll n , k , x[MAXN] , z[MAXN] , cen;

void zDFS(ll r , ll par){
	z[r] = mark[r];
	for(auto i : adj[r]){
		if(i == par) continue;
		zDFS(i , r);
		z[r] += z[i];
	}
	return;
}

ll find_centroid(ll r , ll par){
	for(auto i : adj[r]){
		if(i == par) continue;
		if(z[i] > k){
			return find_centroid(i , r);
		}
	}
	return r;
}

void zrDFS(ll r , ll par , ll x){
	if(mark[r]) zr[x].push_back(r);
	for(auto i : adj[r]){
		if(i == par) continue;
		if(r == cen) x++;
		zrDFS(i , r , x);
	}
	return;
}

priority_queue<pll> pq;
vector<pll> ans;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(x , 0 , sizeof(x));
	cin>>n>>k;
	for(ll i = 1 ; i < n ; i++){
		ll v , u ;
		cin>>v>>u; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
	}
	ll lm = k << 1;
	for(ll i = 0 ; i < lm ; i++){
		ll v;
		cin>>v; v--;
		mark[v] = true;
	}
	zDFS(0 , -1);
	cen = find_centroid(0 , -1);
	zrDFS(cen , -1 , 0);
	lm = adj[cen].size();
	for(ll i = 0 ; i <= lm ; i++){
		pq.push({zr[i].size() , i});
	}
	while(true){
		pll p = pq.top() , q; pq.pop();
		q = pq.top(); pq.pop();
		if(q.first == 0) break;
		ans.push_back({zr[p.second][x[p.second]++] + 1 , zr[q.second][x[q.second]++] + 1});
		pq.push({zr[p.second].size() - x[p.second] , p.second});
		pq.push({zr[q.second].size() - x[q.second] , q.second});
	}
	cout<<"1\n"<<++cen<<'\n';
	for(auto p : ans){
		cout<<p.first<<' '<<p.second<<' '<<cen<<'\n';
	}
	return 0;
}

/*

*/