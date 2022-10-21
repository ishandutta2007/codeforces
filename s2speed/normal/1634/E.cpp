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

inline ll tav(ll n , ll k){
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

ll k[maxn];
vector<ll> a[maxn] , v , adj[maxn];
vector<char> ans[maxn];
vector<pll> ed;
ll z[maxn] , u[maxn] , x[maxn] , d[maxn];
bitset<maxn> mark;

void tour_Euleri(ll r){
	while(x[r] < d[r]){
		if(mark[adj[r][x[r]]]){
			x[r]++;
			continue;
		}
		ll i = adj[r][x[r]];
		ans[z[i]][u[i]] = 'L';
		ans[z[i]][u[i] + 1] = 'R';
		ll v = ed[i].second;
		if(ed[i].first != r){
			swap(ans[z[i]][u[i]] , ans[z[i]][u[i] + 1]);
			v = ed[i].first;
		}
		x[r]++;
		mark[i] = true;
		tour_Euleri(v);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(d , 0 , sizeof(d));
	memset(x , 0 , sizeof(x));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>k[i];
		a[i].resize(k[i]);
		ans[i].resize(k[i]);
		if(k[i] & 1){
			cout<<"NO\n";
			return 0;
		}
		for(ll j = 0 ; j < k[i] ; j++){
			cin>>a[i][j];
			v.push_back(a[i][j]);
		}
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < k[i] ; j++){
			a[i][j] = lower_bound(all(v) , a[i][j]) - v.begin();
		}
		for(ll j = 0 ; j < k[i] ; j += 2){
			ed.push_back({a[i][j] , a[i][j + 1]});
			adj[a[i][j]].push_back(cnt); adj[a[i][j + 1]].push_back(cnt);
			d[a[i][j]]++; d[a[i][j + 1]]++;
			z[cnt] = i; u[cnt++] = j;
		}
	}
	for(ll i = 0 ; i < maxn ; i++){
		if(d[i] & 1){
			cout<<"NO\n";
			return 0;
		}
		if(x[i] < d[i]) tour_Euleri(i);
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < k[i] ; j++){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
	return 0;
}