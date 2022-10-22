#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 12 , maxk = 6e4 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> adj[maxn];
ll tv[maxn] , dp[maxk];
vector<pll> s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++) tv[i] = 3 * tv[i - 1];
	ll n , m , k;
	cin>>n>>m>>k;
	for(ll i = 0 ; i < m ; i++){
		ll v , u;
		cin>>v>>u; v--; u--;
		adj[v][u] = adj[u][v] = true;
	}
	ll lm = tv[n] , ans = 0;
	for(ll mask = 0 ; mask < lm ; mask++){
		ll cnt[] = {0 , 0 , 0};
		ll h = mask;
		for(ll j = 0 ; j < n ; j++){
			cnt[h % 3]++;
			h /= 3;
		}
		s.push_back({-cnt[0] , mask});
	}
	sort(all(s));
	for(ll e = 0 ; e < lm ; e++){
		ll mask = s[e].second;
		ll cnt[] = {0 , 0 , 0} , a[maxn];
		vector<ll> l;
		ll h = mask;
		for(ll j = 0 ; j < n ; j++){
			cnt[a[j] = h % 3]++;
			if(a[j] == 2){
				l.push_back(j);
			}
			h /= 3;
		}
		if(cnt[2] < 2) continue;
		if(cnt[0] > n - 2) continue;
		if(cnt[0] == n - 2){
			dp[mask] = adj[l[0]][l[1]];
			continue;
		}
		ll o = l.back() , msk = mask - 2 * tv[o];
		for(ll j = 0 ; j < n ; j++){
			if(a[j] != 1) continue;
			if(!adj[o][j]) continue;
			h = dp[msk] + dp[msk + tv[j]];
			dp[mask] += h;
		}
		if(cnt[0] == 0 && cnt[2] == k) ans += dp[mask];
	}
	cout<<ans<<'\n';
	return 0;
}