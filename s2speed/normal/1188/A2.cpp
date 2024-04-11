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

vector<pll> ed;
ll w[maxn];
vector<ll> adj[maxn];
ll dr[maxn] , l[maxn];
vector<plll> ans;

void lDFS(ll r , ll par){
	if(dr[r] == 1){
		l[r] = r;
		return;
	}
	for(auto i : adj[r]){
		if(i == par) continue;
		lDFS(i , r);
		l[r] = l[i];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dr , 0 , sizeof(dr));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n - 1 ; i++){
		ll v , u;
		cin>>v>>u>>w[i]; v--; u--;
		ed.push_back({v , u});
		adj[v].push_back(u); adj[u].push_back(v);
		dr[v]++; dr[u]++;
	}
	if(n == 2){
		cout<<"YES\n1\n1 2 "<<w[0]<<'\n';
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		if(dr[i] == 2){
			cout<<"NO\n";
			return 0;
		}
	}
	ll j = 0;
	for(auto p : ed){
		ll v = p.first , u = p.second;
		if(dr[v] == 1) swap(v , u);
		lDFS(v , -1);
		ll a = -1 , b = -1 , c = -1 , d = -1;
		for(auto i : adj[v]){
			if(i == u) continue;
			if(a == -1){
				a = l[i];
			} else if(b == -1){
				b = l[i];
			}
		}
		for(auto i : adj[u]){
			if(i == v) continue;
			if(c == -1){
				c = l[i];
			} else if(d == -1){
				d = l[i];
			}
		}
		if(dr[u] == 1) c = d = u;
		ll h = w[j++] >> 1;
		ans.push_back({{a , c} , h});
		ans.push_back({{b , d} , h});
		ans.push_back({{a , b} , -h});
		if(c != d) ans.push_back({{c , d} , -h});
	}
	cout<<"YES\n"<<sze(ans)<<'\n';
	for(auto q : ans){
		pll p = q.first;
		cout<<p.first + 1<<' '<<p.second + 1<<' '<<q.second<<'\n';
	}
	return 0;
}