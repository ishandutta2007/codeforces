#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

ll a[maxn];

void solve(){
	ll n , m[2] , sum[2] , ans = inf , cnt[] = {1 , 1};
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	m[0] = sum[0] = a[0];
	m[1] = sum[1] = a[1];
	ans = 1ll * n * (a[0] + a[1]);
	for(ll i = 2 ; i < n ; i++){
		cnt[i % 2]++;
		sum[i % 2] += a[i];
		if(a[i] < m[i % 2]){
			m[i % 2] = a[i];
		}
		ans = min(ans , sum[0] + sum[1] + 1ll * (n - cnt[0]) * m[0] + 1ll * (n - cnt[1]) * m[1]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}