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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , par[maxn];
int cnt[200 * maxn];
vector<ll> adj[maxn];
bitset<maxn> dis;

void dDFS(ll r){
	bool c = dis[r] ^ 1;
	for(auto i : adj[r]){
		dis[i] = c;
		dDFS(i);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i < n ; i++){
		cin>>par[i]; par[i]--;
		adj[par[i]].push_back(i);
		cnt[par[i]]++;
	}
	dDFS(0);
	for(int i = 0 ; i < n ; i++){
		if(cnt[i] == 0){
			if(!dis[i]) dis.flip();
			break;
		}
	}
	memset(cnt , 0 , sizeof(cnt));
	ll s = 0 , cn = 0;
	for(ll i = 0 ; i < n ; i++){
		if(dis[i]){
			cn++;
			cnt[a[i]]++;
			s ^= a[i];
		}
	}
	ll ans = 0;
	if(s == 0){
		ans += 1ll * cn * (cn - 1) / 2;
		ans += 1ll * (n - cn) * (n - cn - 1) / 2;
	}
	for(ll i = 0 ; i < n ; i++){
		if(dis[i]) continue;
		ans += cnt[a[i] ^ s];
	}
	cout<<ans<<'\n';
	return 0;
}