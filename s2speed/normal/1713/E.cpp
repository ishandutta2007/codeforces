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

const ll maxn = 1e3 + 17 , md = 1e9 + 7 , inf = 2e16;

ll ds[maxn];
bool dc[maxn];
vector<ll> dsu[maxn];

void merge(ll v , ll u , bool c){
	v = ds[v]; u = ds[u];
	if(v == u) return;
	if(sze(dsu[u]) > sze(dsu[v])) swap(v , u);
	for(auto i : dsu[u]){
		ds[i] = v;
		dsu[v].push_back(i);
		dc[i] ^= c;
	}
	dsu[u].clear();
	return;
}

ll a[maxn][maxn];

void solve(){
	ll n;
	cin>>n;
	iota(ds , ds + n , 0);
	fill(dc , dc + n , false);
	for(ll i = 0 ; i < n ; i++){
		dsu[i].clear(); dsu[i].push_back(i);
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			cin>>a[i][j];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			if(a[i][j] == a[j][i]) continue;
			merge(i , j , (a[j][i] < a[i][j]) ^ (dc[i] ^ dc[j]));
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j < n ; j++){
			if(dc[i] ^ dc[j]) swap(a[i][j] , a[j][i]);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < n ; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return;
}

/*
1
4
3 3 1 2
1 1 3 1
3 2 3 2
2 3 3 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}