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

int ds[maxn];
vector<int> dsu[maxn];
bitset<maxn> sd;

bool merge(int v , int u , bool c){
	if(ds[v] == ds[u]){
		return (sd[v] ^ sd[u] ^ c);
	}
	if(sze(dsu[ds[v]]) < sze(dsu[ds[u]])) swap(v , u);
	int w = ds[u];
	bool ch = (sd[v] ^ sd[u] ^ c);
	for(auto i : dsu[w]){
		ds[i] = ds[v];
		dsu[ds[v]].push_back(i);
		sd[i] = sd[i] ^ ch;
	}
	dsu[w].clear();
	dsu[w].shrink_to_fit();
	return false;
}

void clear(ll n){
	for(int i = 0 ; i < n ; i++){
		dsu[i].clear();
		dsu[i].shrink_to_fit();
	}
	return;
}

void solve(){
	int n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		ds[i] = i;
		dsu[i].push_back(i);
		sd[i] = false;
	}
	bool res = true;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		string s;
		bool c;
		cin>>v>>u>>s; v--; u--; c = (s[0] == 'i');
		if(merge(v , u , c)){
			res = false;
		}
	}
	if(!res){
		cout<<"-1\n";
		clear(n);
		return;
	}
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int cnt[] = {0 , 0};
		for(auto j : dsu[i]){
			cnt[sd[j]]++;
		}
		ans += max(cnt[0] , cnt[1]);
	}
	cout<<ans<<'\n';
	clear(n);
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}