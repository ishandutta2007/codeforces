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
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 2e16;

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

ll a[MAXN] , nxt[MAXN] , f[MAXN] , l[MAXN] , nd[MAXN];
vector<ll> ans;

void solve(){ ans.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		f[i] = i;
		l[i] = i;
		nd[i] = (i + 1) % n;
		nxt[i] = (i + 1) % n;
	}
	ll i = 0;
	while(true){
		if(gcd(a[l[i]] , a[f[nxt[i]]]) == 1){
			ans.push_back(f[nxt[i]] + 1);
			nd[l[i]] = nd[f[nxt[i]]];
			if(f[nxt[i]] == l[nxt[i]]){
				if(nxt[i] == i) break;
				nxt[i] = nxt[nxt[i]];
			} else {
				f[nxt[i]] = nd[f[nxt[i]]];
			}
			i = nxt[i];
		} else {
			if(nxt[i] == i) break;
			l[i] = l[nxt[i]];
			nxt[i] = nxt[nxt[i]];
		}
	}
	cout<<ans.size()<<' ';
	for(auto i : ans){
		cout<<i<<' ';
	}
	cout<<'\n';
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

/*

*/