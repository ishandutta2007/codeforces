#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;

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

struct fentree {

	int sz = 0;
	vector<int> val;

	void init(int n){
		sz = n;
		val.assign(sz , 0);
		return;
	}

	void set(int i , int v){
		int ind = i;
		while(ind < sz){
			val[ind] += v;
			ind |= (ind + 1);
		}
		return;
	}

	int cal(int i){
		int ind = i , h = 0;
		while(ind >= 0){
			h += val[ind];
			ind &= (ind + 1); ind--;
		}
		return h;
	}

	void clear(){
		sz = 0;
		val.clear();
	}
	
};

bool mark[MAX_N] , dead[MAX_N];
int n , l , w , z[MAX_N] , sz , dep = -1 , dis = 0 , cnt[MAX_N];
vector<pii> adj[MAX_N] , v , o;
ll ans = 0 , h;
fentree ft;

void bcDFS(int r , int par){
	if(!~par) sz = 0;
	sz++;
	mark[r] = true;
	for(auto p : adj[r]){
		int i = p.first;
		if(i == par || dead[i]) continue;
		bcDFS(i , r);
	}
	z[r] = 1;
	for(auto p : adj[r]){
		int i = p.first;
		if(i == par || dead[i]) continue;
		z[r] += z[i];
	}
	return;
}

int find_centroid(int r , int par){
	for(auto p : adj[r]){
		int i = p.first;
		if(i == par || dead[i]) continue;
		if(z[i] > sz / 2){
			return find_centroid(i , r);
		}
	}
	return r;
}

void acDFS(int r , int par , int yal){
	dep++;
	dis += yal;
	if(~par){
		o.push_back({dis , dep});
		v.push_back({dis , dep});
	}
	if(dep <= l && dis <= w && ~par) ans += 2;
	for(auto p : adj[r]){
		int i = p.first , u = p.second;
		if(i == par || dead[i]) continue;
		acDFS(i , r , u);
		if(!~par){
			sort(all(o));
			z[i] = o.size();
			ft.clear();
			int y = z[i] - 1;
			for(int j = 0 ; j <= z[i] ; j++){
				cnt[j] = 0;
			}
			for(int j = 0 ; j < z[i] ; j++){
				cnt[o[j].second]++;
			}
			ft.init(n);
			for(int j = 0 ; j <= z[i] ; j++){
				ft.set(j , cnt[j]);
			}
			for(int x = 0 ; x < z[i] ; x++){
				while(o[y].first + o[x].first > w && y > -1){
					ft.set(o[y].second , -1);
					y--;
				}
				h += ft.cal(l - o[x].second);
			}
			o.clear();
		}
	}
	dis -= yal;
	dep--;
	return;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>l>>w;
	for(int i = 1 ; i < n ; i++){
		int v , o;
		cin>>v>>o; v--;
		adj[v].push_back({i , o}); adj[i].push_back({v , o});
	}
	fill(dead , dead + n , false);
	int dcnt = 0;
	while(dcnt < n){
		for(int i = 0 ; i < n ; i++){
			mark[i] = dead[i];
		}
		for(int i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			h = 0;
			bcDFS(i , -1);
			int cen = find_centroid(i , -1);
			acDFS(cen , -1 , 0);
			sort(all(v));
			ft.clear();
			int y = sz - 2;
			for(int j = 0 ; j < sz ; j++){
				cnt[j] = 0;
			}
			for(int j = 0 ; j < sz - 1 ; j++){
				cnt[v[j].second]++;
			}
			ft.init(n);
			for(int j = 0 ; j < sz ; j++){
				ft.set(j , cnt[j]);
			}
			for(int x = 0 ; x < sz - 1 ; x++){
				while(v[y].first + v[x].first > w && y > -1){
					ft.set(v[y].second , -1);
					y--;
				}
				ans += ft.cal(l - v[x].second);
			}
			ans -= h;
			dcnt++;
			dead[cen] = true;
			v.clear();
		}
	}
	ans /= 2;
	cout<<ans<<'\n';
	return 0;
}

/*
10 3 100000
1 4372
1 8809
2 2085
2 2202
3 9004
3 5568
4 8984
4 1650
5 2369
*/