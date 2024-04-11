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

vector<plll> ed;
vector<ll> adj[maxn];
bitset<maxn> ch , mark;
ll d[maxn] , cur = 0 , x[maxn];
priority_queue<pll , vector<pll> , greater<pll>> pq;

void cDFS(ll r){
	ch[r] = cur;
	mark[r] = true;
	cur ^= 1;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		cDFS(i);
	}
	cur ^= 1;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(d , 0 , sizeof(d));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll t , v , u;
		cin>>t>>v>>u; t--; v--; u--;
		adj[v].push_back(u); adj[u].push_back(v);
		ed.push_back({{v , u} , t});
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		cDFS(i);
	}
	for(ll i = 0 ; i < n ; i++) adj[i].clear();
	for(auto p : ed){
		ll v = p.first.first , u = p.first.second , t = p.second;
		if(ch[v] == ch[u]){
			cout<<"NO\n";
			return 0;
		}
		if(ch[v] ^ t) swap(v , u);
		adj[v].push_back(u);
//		cout<<v<<' '<<u<<'\n';
		d[u]++;
	}
	for(ll i = 0 ; i < n ; i++){
		pq.push({d[i] , i});
//		cout<<d[i]<<' ';
	}
//	cout<<'\n';
	ll cnt = 0;
	while(!pq.empty()){
		pll p = pq.top(); pq.pop();
		ll v = p.second;
		if(d[v] != p.first) continue;
		if(d[v]){
			cout<<"NO\n";
			return 0;
		}
		x[v] = cnt++;
		for(auto i : adj[v]){
			d[i]--;
			pq.push({d[i] , i});
		}
	}
	cout<<"YES\n";
	for(ll i = 0 ; i < n ; i++){
		cout<<(ch[i] ? 'R' : 'L')<<' '<<x[i]<<'\n';
	}
	return 0;
}