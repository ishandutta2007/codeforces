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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 1e6 + 15 , MAXA = 1e7 + 15 , md = 2000000357 , p = 31 , inf = 1e15;

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

int t[MAXA];
ll n , a[MAXN] , k;

bool check(ll x){
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] < x) continue;
		ll q = a[i] / x , res = t[q] , h = t[q];
		h *= 2;
		if(x == a[i] / h + 1){
			res = max(res , a[i] % h);
		}
		cnt += res;
	}
	return (cnt >= k);
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int h = 1;
	t[0] = 0;
	for(int i = 1 ; i < MAXA ; i++){
		if(i == h){
			t[i] = h;
			h <<= 1;
		} else {
			t[i] = t[i - 1];
		}
	}
	cin>>n>>k;
	ll sum = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		sum += a[i];
	}
	if(sum < k){
		cout<<"-1\n";
		return 0;
	}
	ll l = 0 , r = 1e7 + 1;
	while(l < r - 1){
		ll m = (r + l) / 2;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
	return 0;
}

/*
1 3
15
*/