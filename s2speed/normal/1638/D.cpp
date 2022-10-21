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

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n , m;
ll a[maxn][maxn];
vector<plll> ans;
bitset<maxn> ch[maxn];
vector<pll> bfs , h;

void paint(ll i , ll j){
	h.clear();
	if(i < 0 || j < 0 || i == n - 1 || j == m - 1) return;
	for(ll x = i ; x <= i + 1 ; x++){
		for(ll y = j ; y <= j + 1 ; y++){
			if(ch[x][y]) continue;
			h.push_back({x , y});
		}
	}
	if(h.empty()) return;
	ll cl = a[h[0].first][h[0].second];
	bool f = true;
	for(auto p : h){
		ll x = p.first , y = p.second;
		f &= (a[x][y] == cl);
	}
	if(!f) return;
	ans.push_back({{i , j} , cl});
	for(auto p : h){
		ll x = p.first , y = p.second;
		ch[x][y] = true;
		bfs.push_back({x , y});
	}
	return;
}

void BFS(){
	ll x = 0;
	while(x < sze(bfs)){
		pll p = bfs[x++];
		ll i = p.first , j = p.second;
		paint(i , j);
		paint(i - 1 , j);
		paint(i , j - 1);
		paint(i - 1 , j - 1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
		}
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		for(ll j = 0 ; j < m - 1 ; j++){
			paint(i , j);
		}
	}
	BFS();
	if(sze(bfs) < n * m){
		cout<<"-1\n";
		return 0;
	}
	cout<<sze(ans)<<'\n';
	reverse(all(ans));
	for(auto q : ans){
		pll p = q.first;
		cout<<p.first + 1<<' '<<p.second + 1<<' '<<q.second<<'\n';
	}
	return 0;
}