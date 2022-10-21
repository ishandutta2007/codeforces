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

set<ll> s[2 * maxn];
bitset<maxn> a[maxn];
ll dp[maxn][maxn][2];

pll get(ll x , ll y){
	ll h = x - y;
	ll i , j;
	if(h < 0){
		i = 0;
		j = -h;
	} else {
		j = 0;
		i = h;
	}
	return {i , j};
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , q;
	cin>>n>>m>>q;
	ll ans = 0;
	for(ll i = n - 1 ; i >= 0 ; i--){
		for(ll j = m - 1 ; j >= 0 ; j--){
			if(i == n - 1){
				dp[i][j][0] = 0;
			} else {
				dp[i][j][0] = dp[i + 1][j][1] + 1;
			}
			if(j == m - 1){
				dp[i][j][1] = 0;
			} else {
				dp[i][j][1] = dp[i][j + 1][0] + 1;
			}
			ans += dp[i][j][0] + dp[i][j][1];
		}
	}
	ans += n * m;
	for(ll i = 0 ; i < n ; i++){
		s[i].insert(-1);
		s[i].insert(dp[i][0][0] + 1);
	}
	for(ll e = n ; e < n + m ; e++){
		ll i = e - n;
		s[e].insert(-1);
		s[e].insert(dp[0][i][1] + 1);
	}
	for(ll e = 0 ; e < q ; e++){
		ll x , y;
		cin>>x>>y; x--; y--;
		a[x][y].flip();
		pll p = get(x , y);
		ll i , j , di , dj;
		if(p.first == 0 && p.second == 0){
			i = 0; j = n; di = dj = x + y;
		} else {
			if(p.first == 0){
				i = n + p.second;
				di = x + y - p.second;
			} else {
				i = p.first;
				di = y + x - i;
			}
			j = i - 1; dj = di + 1;
		}
		ll h = 0;
		s[i].erase(di);
		auto it = s[i].upper_bound(di) , et = it;
		it--;
		h += 1ll * (*et - di) * (di - *it);
		s[j].erase(dj);
		it = s[j].upper_bound(dj); et = it;
		it--;
		h += 1ll * (*et - dj) * (dj - *it);
		h--;
		if(a[x][y]){
			ans -= h;
			s[i].insert(di);
			s[j].insert(dj);
		} else {
			ans += h;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

/*
3 4 1
1 4
*/