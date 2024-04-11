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

ll n , m;
ll cnt[maxn];

bool check(ll x){
	ll res = 0;
	for(ll i = 0 ; i < n ; i++){
		if(x <= cnt[i]){
			res += x;
		} else {
			res += cnt[i] + (x - cnt[i]) / 2;
		}
	}
	return (res >= m);
}

void solve(){
	cin>>n>>m;
	fill(cnt , cnt + n , 0);
	for(ll i = 0 ; i < m ; i++){
		ll h;
		cin>>h; h--;
		cnt[h]++;
	}
	ll l = 0 , r = m + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<r<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}