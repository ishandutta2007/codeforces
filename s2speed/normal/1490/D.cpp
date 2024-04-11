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

const ll MAXN = 1e2 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;
// check problem statement

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

bitset<MAXN> mark;
ll dis[MAXN] , a[MAXN];

void solve(){
	mark.reset();
	ll n , m , ind;
	cin>>n; mark[n] = true;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll k = 0 ; mark.count() <= n ; k++){
		m = 0; ind = -1;
		for(ll i = 0 ; i <= n ; i++){
			if(mark[i]){
				if(ind == -1) continue;
				mark[ind] = true;
				dis[ind] = k;
				m = 0;
				ind = -1;
				continue;
			}
			if(m < a[i]){
				m = a[i];
				ind = i;
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<dis[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/