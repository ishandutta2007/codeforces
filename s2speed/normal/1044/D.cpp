#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
//#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 4e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

map<int , int> mp;
int ds[31][maxn] , c[31][maxn];

int dsu(int v , int j){
	if(ds[j][v] == v){
	    return v;
	}
	int h = dsu(ds[j][v] , j);
	c[j][v] ^= c[j][ds[j][v]];
	ds[j][v] = dsu(ds[j][v] , j);
	return ds[j][v];
}

void merge(int v , int u , bool o , int j){
	int dv = dsu(v , j) , du = dsu(u , j);
	if(dv == du) return;
	bool h = c[j][v] ^ c[j][u] ^ o;
	c[j][du] ^= h;
	ds[j][du] = dv;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q , ls = 0 , cnt = 0;
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		int t;
		cin>>t;
		if(t == 1){
			int l , r , x;
			cin>>l>>r>>x;
			l ^= ls; r ^= ls; x ^= ls;
			if(l > r) swap(l , r);
			r++;
			if(!mp.count(l)){
				for(int j = 0 ; j < 30 ; j++){
					ds[j][cnt] = cnt;
					c[j][cnt] = 0;
				}
				mp[l] = cnt++;
			}
			if(!mp.count(r)){
				for(int j = 0 ; j < 30 ; j++){
					ds[j][cnt] = cnt;
					c[j][cnt] = 0;
				}
				mp[r] = cnt++;
			}
			l = mp[l]; r = mp[r];
			bool o = true;
			for(int j = 0 ; j < 30 ; j++){
				int dl = dsu(l , j) , dr = dsu(r , j);
				bool h = (x & (1 << j));
				if(dl == dr && c[j][l] ^ c[j][r] ^ h){
				    o = false;
				}
			}
			if(!o) continue;
			for(int j = 0 ; j < 30 ; j++){
				bool h = (x & (1 << j));
				merge(l , r , h , j);
			}
		} else {
			int l , r;
			cin>>l>>r;
			l ^= ls; r ^= ls;
			if(l > r) swap(l , r);
			r++;
			if(!mp.count(l)){
				for(int j = 0 ; j < 30 ; j++){
					ds[j][cnt] = cnt;
					c[j][cnt] = 0;
				}
				mp[l] = cnt++;
			}
			if(!mp.count(r)){
				for(int j = 0 ; j < 30 ; j++){
					ds[j][cnt] = cnt;
					c[j][cnt] = 0;
				}
				mp[r] = cnt++;
			}
			l = mp[l]; r = mp[r];
			bool o = true;
			for(int j = 0 ; j < 30 ; j++){
				int dl = dsu(l , j) , dr = dsu(r , j);
				o &= (dl == dr);
			}
			if(!o){
				ls = 1;
				cout<<-1<<'\n';
				continue;
			}
			ls = 0;
			for(int j = 0 ; j < 30 ; j++){
				ls += (1 << j) * (c[j][l] ^ c[j][r]);
			}
			cout<<ls<<'\n';
		}
	}
	return 0;
}

/*
4
1 1 2 5
1 2 3 6
1 1 3 0
2 3 3
*/