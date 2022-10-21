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

const ll maxn = 2e5 + 17 , md = 998244353 , inf = 2e16;

ll a[maxn] , b[maxn];
bitset<maxn> mark;
ll ps[maxn];

void solve(){
	ll n , s;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		mark[i] = false;
		b[i] = -1;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		if(h != -2){
			b[h] = a[i];
			mark[a[i]] = true;
		}
	}
	ps[0] = !mark[0];
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + !mark[i];
	}
	ll ans = 1 , cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(b[i] == -1){
			ans *= ps[min(n - 1 , i + s)] - cnt; ans %= md;
			cnt++;
		} else if(b[i] > i + s){
			ans = 0;
		}
	}
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