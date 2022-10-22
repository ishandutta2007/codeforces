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
struct plll { ll x , y , z; };
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

ll a[maxn][2] , cnt[2] , sum[2];

void solve(){
	cnt[0] = cnt[1] = sum[0] = sum[1] = 0;
	ll n , l , r , ans = 0;
	cin>>n>>l>>r;
	for(ll i = 0 ; i < n ; i++){
		a[i][0] = a[i][1] = 0;
	}
	for(ll i = 0 ; i < l ; i++){
		ll h;
		cin>>h; h--;
		a[h][0]++;
	}
	for(ll i = 0 ; i < r ; i++){
		ll h;
		cin>>h; h--;
		a[h][1]++;
	}
	for(ll i = 0 ; i < n ; i++){
		if(a[i][0] > a[i][1]){
			a[i][0] -= a[i][1];
			cnt[0] += a[i][0] & 1;
			sum[0] += a[i][0];
		} else {
			a[i][1] -= a[i][0];
			cnt[1] += a[i][1] & 1;
			sum[1] += a[i][1];
		}
	}
	if(cnt[1] > cnt[0]){
		swap(cnt[0] , cnt[1]); swap(sum[0] , sum[1]);
	}
	ans = (sum[0] + sum[1]) >> 1;
	ans += max(0ll , cnt[0] - sum[1]) >> 1;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}