#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};
 
const ll MAX_N = 1e3 + 20 , MAX_NN = 1e6 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

int ds[MAX_NN] , dsz[MAX_NN];

int dsu(int v){
	return ds[v] = (ds[v] == v ? v : dsu(ds[v]));
}

void unite(int v , int u){
	v = dsu(v); u = dsu(u);
	if(v == u) return;
	if(dsz[u] > dsz[v]) swap(u , v);
	dsz[v] += dsz[u]; dsz[u] = 0;
	ds[u] = v;
	return;
}

bool b[MAX_N][MAX_N];
vector<ll> d , o , adj[MAX_NN];
ll a[MAX_N][MAX_N] , dis[MAX_NN];
vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , k , ans = -1;
	cin>>n>>m>>k;
	if(k > 1000000000ll * n * m){
		cout<<"NO\n";
		return 0;
	}
	db sq = sqrt(k);
	for(int i = 1 ; i <= sq ; i++){
		if(k % i == 0){
			d.push_back(i);
			if(i != sq){
				d.push_back(k / i);
			}
		}
	}
	sort(d.begin() , d.end());
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			b[i][j] = false;
			cin>>a[i][j];
			v.push_back({a[i][j] , i * m + j});
		}
	}
	sort(v.begin() , v.end() , greater<pll>() );
	ll x = 0 , lm = d.size();
	for(int e = 0 ; e < lm && ans == -1 ; e++){
		o.clear();
		ll h = k / d[e];
		while(x < n * m){
			if(v[x].first <= h) break;
			ll i , j , q = v[x].second;
			i = q / m;
			j = q % m;
			ds[q] = q; dsz[q] = 1;
			b[i][j] = true;
			if(i > 0){
				if(b[i - 1][j]){
					unite(q , q - m);
				}
			}
			if(i < n - 1){
				if(b[i + 1][j]){
					unite(q , q + m);
				}
			}
			if(j > 0){
				if(b[i][j - 1]){
					unite(q , q - 1);
				}
			}
			if(j < m - 1){
				if(b[i][j + 1]){
					unite(q , q + 1);
				}
			}
			x++;
		}
		while(x < n * m){
			if(v[x].first != h) break;
			ll i , j , q = v[x].second;
			i = q / m;
			j = q % m;
			o.push_back(q);
			ds[q] = q; dsz[q] = 1;
			b[i][j] = true;
			if(i > 0){
				if(b[i - 1][j]){
					unite(q , q - m);
				}
			}
			if(i < n - 1){
				if(b[i + 1][j]){
					unite(q , q + m);
				}
			}
			if(j > 0){
				if(b[i][j - 1]){
					unite(q , q - 1);
				}
			}
			if(j < m - 1){
				if(b[i][j + 1]){
					unite(q , q + 1);
				}
			}
			x++;
		}
		for(auto u : o){
			if(dsz[dsu(u)] >= d[e]){
				ans = u;
				break;
			}
		}
	}
	if(ans == -1){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(!b[i][j]) continue;
			int q = i * m + j;
			if(dsu(q) != ds[ans]) continue;
			if(i < n - 1){
				if(b[i + 1][j]){
					if(dsu(q + m) == ds[ans]){
						adj[q].push_back(q + m); adj[q + m].push_back(q);
					}
				}
			}
			if(j < m - 1){
				if(b[i][j + 1]){
					if(dsu(q + 1) == ds[ans]){
						adj[q].push_back(q + 1); adj[q + 1].push_back(q);
					}
				}
			}
		}
	}
	lm = k / a[ans / m][ans % m];
	vector<ll> o;
	o.push_back(ans);
	ll g = 0;
	fill(dis , dis + n * m , 1e8); dis[ans] = 0; ans = a[ans / m][ans % m];
	while(o.size() < lm){
		ll q = o[g++];
		for(auto i : adj[q]){
			if(dis[i] > dis[q] + 1){
				o.push_back(i);
				dis[i] = dis[q] + 1;
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			a[i][j] = 0;
		}
	}
	for(int i = 0 ; i < lm ; i++){
		ll q = o[i];
		a[q / m][q % m] = ans;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

/*
4 4 24
5 1 1 5
5 1 1 5
5 1 1 5
5 4 5 5
*/