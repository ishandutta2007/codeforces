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

const ll MAXN = 4e5 + 15 , md = 1e9 + 7 , inf = 1e9;

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

ll a[MAXN];
set<ll> s[2] , unq;
bitset<MAXN> mark;
ll x[] = {2 , 1} , cnt[] = {0 , 0};

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , ans = 0;
	cin>>n>>m;
	m = min(m , 2 * n);
	for(ll i = 1 ; i <= m ; i++){
		s[i % 2].insert(i);
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		s[a[i] % 2].insert(a[i]);
		cnt[a[i] % 2]++;
		if(a[i] <= m){
			mark[a[i]] = true;
		}
	}
	if(n % 2){
		cout<<"-1\n";
		return 0;
	}
	if(s[0].size() < n / 2 || s[1].size() < n / 2){
		cout<<"-1\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		if(unq.count(a[i])){
			ll o = (cnt[0] > cnt[1]);
			if(cnt[0] == cnt[1]){
				o = a[i] % 2;
			}
			ans++;
			cnt[o]++;
			cnt[a[i] % 2]--;
			a[i] = x[o];
			x[o] += 2;
			while(mark[x[o]]) x[o] += 2;
		} else {
			unq.insert(a[i]);
		}
	}
	ll o = (cnt[0] > cnt[1]);
	for(ll i = 0 ; i < n && cnt[o] < cnt[1 - o] ; i++){
		if(a[i] % 2 != o){
			ans++;
			cnt[o]++;
			cnt[a[i] % 2]--;
			a[i] = x[o];
			x[o] += 2;
			while(mark[x[o]]) x[o] += 2;
		}
	}
	cout<<ans<<'\n';
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*

*/