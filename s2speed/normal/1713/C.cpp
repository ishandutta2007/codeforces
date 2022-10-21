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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

bitset<maxn> mark;
ll ans[maxn];

void solve(){
	ll n;
	cin>>n;
	ll v = n - 1;
	while(v > 0){
		ll r = mark._Find_next(v - 1);
		ll h = v;
		while(true){
			ans[h] = r - h;
			if(r - h == v) break;
			h--;
		}
		v = h - 1;
	}
	if(v == 0) ans[0] = 0;
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 0 ; i * i <= 2e5 ; i++){
		mark[i * i] = true;
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}