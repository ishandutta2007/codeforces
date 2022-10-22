#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,no-stack-protector")

#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define mp make_pair
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return ((b == 0) ? a : gcd(b , a % b));
}

const ll MAXN = 1e5 + 15 , md = 1e9 + 7 , inf = 1e18;

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

ll dp[MAXN] , pd[MAXN] , cnt[MAXN];
vector<ll> v , a;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , g = 0;
	cin>>n; a.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	v.assign(n , inf);
	for(ll i = 0 ; i < n ; i++){
		ll q = lower_bound(all(v) , a[i]) - v.begin();
		dp[i] = q + 1;
		v[q] = a[i];
		g = max(g , dp[i]);
	}
	v.clear(); v.assign(n , inf);
	reverse(all(a));
	for(ll i = 0 ; i < n ; i++){
		a[i] = -a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll q = lower_bound(all(v) , a[i]) - v.begin();
		pd[n - i - 1] = q + 1;
		v[q] = a[i];
	}
	g++;
	for(ll i = 0 ; i < n ; i++){
		ll h = dp[i] + pd[i];
		if(h == g){
			cnt[dp[i]]++;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(dp[i] + pd[i] != g){
			cout<<'1';
		} else {
			if(cnt[dp[i]] > 1){
				cout<<'2';
			} else {
				cout<<'3';;
			}
		}
	}
	cout<<'\n';
	return 0;
}

/*

*/