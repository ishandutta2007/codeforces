#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , cnt[maxn] , mt[maxn];
vector<ll> v , ans;
bitset<maxn> mark;

void cDFS(ll r){
	mark[r] = true;
	if(mark[mt[r]]) return;
	cDFS(mt[r]);
	return;
}

void solve(){
	v.clear(); ans.clear();
	ll n , m , lm , h;
	cin>>n>>m; h = n / 3;
	lm = n - 2 * h;
	for(ll i = 0 ; i < n ; i++) cnt[i] = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		cnt[(a[i] - i + n) % n]++;
	}
	for(ll i = 0 ; i < n ; i++){
		if(cnt[i] >= lm) v.push_back(i);
	}
	for(auto k : v){
		for(ll i = 0 ; i < n ; i++) mark[i] = false;
		for(ll i = 0 ; i < n ; i++){
			ll h = (i + k) % n;
			mt[a[i]] = h;
		}
		ll res = n;
		for(ll i = 0 ; i < n ; i++){
			if(mark[i]) continue;
			res--;
			cDFS(i);
		}
		if(res <= m) ans.push_back((n - k) % n);
	}
	sort(all(ans));
	cout<<sze(ans)<<' ';
	for(auto k : ans){
		cout<<k<<' ';
	}
	cout<<'\n';
	return;
}

/*
1
6 0
1 2 3 4 6 5
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}