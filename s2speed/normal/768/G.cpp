#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n;
ll z[maxn] , z1[maxn] , z2[maxn] , zm[maxn] , zc[maxn] , hc[maxn] , ans[maxn] , j[maxn] , root;
vector<ll> adj[maxn];
multiset<ll> s[maxn] , t , r;

void zDFS(ll r){
	z[r] = 1;
	for(auto i : adj[r]){
		zDFS(i);
		z[r] += z[i];
	}
	zm[r] = z1[r] = n - z[r];
	if(zm[r] == 0) zm[r] = inf;
	ll m = -1;
	for(auto i : adj[r]){
		if(z[i] > z1[r]){
			z2[r] = z1[r];
			zc[r] = i;
			z1[r] = z[i];
		} else if(z[i] > z2[r]){
			z2[r] = z[i];
		}
		if(z[i] < zm[r]) zm[r] = z[i];
		if(z[i] > m){
			m = z[i];
			hc[r] = i;
		}
	}
	j[r] = (z1[r] - zm[r]) / 2;
	return;
}

void gDFS(ll v){
	t.erase(t.find(z[v]));
	if(z[v] == 1){
		ans[v] = n - 1;
		s[v].insert(1);
		return;
	}
	r.insert(z[v]);
	for(auto i : adj[v]){
		if(i == hc[v]) continue;
		gDFS(i);
		for(auto j : s[i]){
			t.insert(j);
		}
		t.insert(z[i]);
	}
	gDFS(hc[v]);
	if(v == root && sze(adj[v]) == 1){
		ans[root] = n - 1;
		return;
	}
	for(auto i : adj[v]){
		if(i == hc[v]) continue;
		for(auto j : s[i]){
			t.erase(t.find(j));
		}
		t.erase(t.find(z[i]));
	}
	ans[v] = z1[v];
	if(zc[v] == -1){
		auto it = t.upper_bound(j[v]);
		if(it != t.end()){
			ll h = *it;
			ans[v] = min(ans[v] , max(zm[v] + h , z2[v]));
		}
		if(it != t.begin()){
			it--;
			ll h = *it;
			ans[v] = min(ans[v] , max(z1[v] - h , z2[v]));
		}
		it = r.upper_bound(j[v] + z[v]);
		if(it != r.end()){
			ll h = *it - z[v];
			ans[v] = min(ans[v] , max(zm[v] + h , z2[v]));
		}
		if(it != r.begin()){
			it--;
			ll h = *it - z[v];
			ans[v] = min(ans[v] , max(z1[v] - h , z2[v]));
		}
	} else {
		auto it = s[zc[v]].upper_bound(j[v]);
		if(it != s[zc[v]].end()){
			ll h = *it;
			ans[v] = min(ans[v] , max(zm[v] + h , z2[v]));
		}
		if(it != s[zc[v]].begin()){
			it--;
			ll h = *it;
			ans[v] = min(ans[v] , max(z1[v] - h , z2[v]));
		}
	}
	swap(s[v] , s[hc[v]]);
	for(auto i : adj[v]){
		s[v].insert(z[i]);
		if(i == hc[v]) continue;
		for(auto j : s[i]){
			s[v].insert(j);
		}
	}
	r.erase(r.find(z[v]));
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(z2 , -63 , sizeof(z2));
	memset(zc , -1 , sizeof(zc));
	memset(ans , 63 , sizeof(ans));
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		if(v == -1){
			root = u;
			continue;
		}
		adj[v].push_back(u);
	}
	zDFS(root);
	for(ll i = 0 ; i < n ; i++) t.insert(z[i]);
	gDFS(root);
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}