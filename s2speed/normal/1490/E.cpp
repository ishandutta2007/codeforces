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

const ll MAXN = 2e5 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;
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

vector<pll> v;
vector<ll> ans;
ll ps[MAXN];

void solve(){
	v.clear();
	ans.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back({h , i + 1});
	}
	sort(all(v)); v.push_back({0 , -1});
	ps[0] = v[0].first;
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + v[i].first;
	}
	ll o = n - 1;
	while(o >= 0){
		if(ps[o] < v[o + 1].first) break;
		ans.push_back(v[o].second);
		o--;
	}
	cout<<n - o - 1<<'\n';
	sort(all(ans));
	for(auto i : ans){
		cout<<i<<' ';
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