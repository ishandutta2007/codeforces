#include<bits/stdc++.h>
#include<fstream>
 
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

const ll maxn = 5e3 + 16 , md = 1e9 + 7 , inf = 2e17;

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

bitset<maxn> b;
int ds[maxn];
vector<int> dsu[maxn];
vector<pii> ed[maxn << 1];
pii a[maxn];

void merge(int v , int u , bool k){
	v = ds[v]; u = ds[u];
	if(sze(dsu[v]) < sze(dsu[u])) swap(v , u);
	int w = u;
	for(auto i : dsu[w]){
		dsu[v].push_back(i);
		ds[i] = v;
		if(k) b[i] = 1 - b[i];
	}
	dsu[w].clear();
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int x , y;
		cin>>x>>y;
		a[i] = {x , y};
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			int w = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
			ed[w].push_back({i , j});
		}
	}
	int ans = 0 , cnt = n;
	for(int i = 0 ; i < n ; i++){
		ds[i] = i;
		dsu[i].push_back(i);
	}
	for(int i = (maxn << 1) - 1 ; i > 0 ; i--){
		for(auto p : ed[i]){
			int v = p.first , u = p.second;
			if(ds[v] == ds[u]){
				if(b[v] == b[u]){
					ans = i;
					break;
				}
				continue;
			}
			merge(v , u , b[v] == b[u]);
		}
		if(ans) break;
	}
	cout<<ans<<'\n';
	for(int i = 0 ; i < n ; i++){
		ds[i] = i;
		dsu[i].push_back(i);
	}
	for(int i = (maxn << 1) - 1 ; i > ans ; i--){
		for(auto p : ed[i]){
			int v = p.first , u = p.second;
			if(ds[v] != ds[u]) merge(v , u , false);
		}
	}
	for(int i = 0 ; i < n ; i++){
		cnt -= dsu[i].empty();
	}
	cout<<tav(2 , cnt)<<'\n';
	return 0;
}