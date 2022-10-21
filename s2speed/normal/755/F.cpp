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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> dp , mark , tmp;
ll cnt[maxn] , p[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , k , ans = 0 , z = 0 , y;
	cin>>n>>k; y = k;
	for(ll i = 0 ; i < n ; i++){
		cin>>p[i]; p[i]--;
	}
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		ll v = i , cur = 0;
		while(!mark[v]){
			mark[v] = true;
			v = p[v];
			cur++;
		}
		cnt[cur]++;
		ll h = cur >> 1;
		ans += h << 1;
		y -= h;
		z += cur & 1;
	}
	if(y < 0){
		ans = 2 * k;
	} else {
		ans += min(z , y);
	}
	for(ll i = 1 ; i <= n ; i++){
		while(cnt[i] > 2){
			cnt[i] -= 2;
			cnt[i << 1]++;
		}
	}
	dp[0] = true;
	for(ll i = 1 ; i <= n ; i++){
		while(cnt[i]){
			tmp = dp << i;
			dp |= tmp;
			cnt[i]--;
		}
	}
	cout<<k + 1 - dp[k]<<' '<<ans<<'\n';
	return 0;
}