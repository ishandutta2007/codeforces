#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll n , m , c[maxn] , o , cur;
vector<ll> adj[maxn] , jda[maxn] , ft , v;
vector<pll> cl[maxn];
vector<pllll> ed;
bitset<maxn> mark;

void fDFS(ll r){
	mark[r] = true;
	for(auto i : adj[r]){
		if(mark[i]) continue;
		fDFS(i);
	}
	ft.push_back(r);
	return;
}

void cDFS(ll r){
	c[r] = o;
	for(auto i : jda[r]){
		if(c[i] != -1) continue;
		cDFS(i);
	}
	return;
}

bool check(ll x){
	for(ll i = 0 ; i < m ; i++){
		ll w = ed[i].second.second;
		if(w > x){
			adj[i].push_back(m + i);
			jda[m + i].push_back(i);
		}
	}
	ft.clear();
	mark.reset();
	for(ll i = 0 ; i < cur ; i++){
		if(mark[i]) continue;
		fDFS(i);
	}
	reverse(all(ft));
	o = 0;
	memset(c , -1 , sizeof(c));
	for(auto i : ft){
		if(c[i] != -1) continue;
		cDFS(i);
		o++;
	}
//	for(ll i = 0 ; i < m ; i++){
//		cout<<c[i]<<' ';
//	}
//	cout<<'\n';
//	for(ll i = 0 ; i < m ; i++){
//		cout<<c[i + m]<<' ';
//	}
//	cout<<'\n';
	bool res = true;
	for(ll i = 0 ; i < m ; i++){
		res &= (c[i] != c[i + m]);
	}
	for(ll i = 0 ; i < m ; i++){
		ll w = ed[i].second.second;
		if(w > x){
			adj[i].pop_back();
			jda[m + i].pop_back();
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(ll i = 0 ; i < m ; i++){
		ll v , u , c , t;
		cin>>v>>u>>c>>t; v--; u--;
		cl[v].push_back({c , i}); cl[u].push_back({c , i});
		ed.push_back({{v , u} , {c , t}});
	}
	for(ll i = 0 ; i < n ; i++){
		sort(all(cl[i]));
		ll cnt = 0 , pr = -1 , pi = -1;
		for(auto p : cl[i]){
			if(p.first == pr){
				cnt++;
				adj[m + pi].push_back(p.second);
				jda[p.second].push_back(m + pi);
				adj[m + p.second].push_back(pi);
				jda[pi].push_back(m + p.second);
			}
			pr = p.first;
			pi = p.second;
		}
		if(cnt > 1){
			cout<<"No\n";
			return 0;
		}
	}
	cur = m + m - 1;
	for(ll i = 0 ; i < n ; i++){
		if(cl[i].empty()) continue;
		ll cs = sze(cl[i]);
		adj[++cur].push_back(m + cl[i][0].second);
		jda[m + cl[i][0].second].push_back(cur);
		for(ll j = 1 ; j < cs ; j++){
			adj[cl[i][j].second].push_back(cur);
			jda[cur++].push_back(cl[i][j].second);
			adj[cur].push_back(cur - 1);
			jda[cur - 1].push_back(cur);
			adj[cur].push_back(m + cl[i][j].second);
			jda[m + cl[i][j].second].push_back(cur);
		}
		adj[++cur].push_back(m + cl[i][cs - 1].second);
		jda[m + cl[i][cs - 1].second].push_back(cur);
		for(ll j = cs - 2 ; j >= 0 ; j--){
			adj[cl[i][j].second].push_back(cur);
			jda[cur++].push_back(cl[i][j].second);
			adj[cur].push_back(cur - 1);
			jda[cur - 1].push_back(cur);
			adj[cur].push_back(m + cl[i][j].second);
			jda[m + cl[i][j].second].push_back(cur);
		}
	}
	cur++;
	if(check(0)){
		cout<<"Yes\n0 0\n";
		return 0;
	}
	ll l = 0 , r = 1e9 + 10;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	if(l == 1e9 + 9){
		cout<<"No\n";
		return 0;
	}
	check(l + 1);
	cout<<"Yes\n";
	for(ll i = 0 ; i < m ; i++){
		if(c[i] > c[i + m]){
			v.push_back(i + 1);
		}
	}
	cout<<l + 1<<' '<<sze(v)<<'\n';
	for(auto i : v){
		cout<<i<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
4 4
1 2 1 2
2 3 1 1
4 3 2 1
4 3 2 1
*/