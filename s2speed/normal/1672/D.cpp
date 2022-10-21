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

ll a[maxn] , b[maxn] , x[maxn] , cnt[maxn] , sz[maxn];
vector<ll> ind[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		x[i] = 0;
		ind[i].clear();
		cnt[i] = 1;
		sz[i] = 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		ind[a[i]].push_back(i);
		sz[a[i]]++;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i]; b[i]--;
	}
	if(a[n - 1] != b[n - 1]){
		cout<<"NO\n";
		return;
	}
	ll pt = 0;
	for(ll i = 0 ; i < n ; i++){
		while(a[pt] != b[i]){
			if(++x[a[pt]] == sz[a[pt]]){
				cout<<"NO\n";
				return;
			}
			ll t = ind[a[pt]][x[a[pt]]];
			cnt[t] += cnt[pt++];
		}
		if(--cnt[pt] == 0){
			++x[a[pt++]];
		}
	}
	cout<<"YES\n";
	return;
}

/*
1
5
1 2 1 3 1
2 1 3 1 1
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}