#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 1e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll a[MAXN] , dp[MAXN];
vector<ll> v;
set<ll> s;

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , ans = 2;
	cin>>n>>a[0]; a[0]--;
	v.push_back(a[0]);
	for(ll i = 1 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		if(a[i - 1] != a[i]){
			v.push_back(a[i]);
		}
	}
	ll vs = v.size();
	if(vs <= 2){
		cout<<vs<<'\n';
		return 0;
	}
	s.insert(v[0]); s.insert(v[1]);
	for(ll i = 2 ; i < vs ; i++){
		if(s.count(v[i])){
			s.clear();
			s.insert(v[i - 1]);
			s.insert(v[i]);
		} else {
			ans++;
			s.insert(v[i]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*
11
7 10 9 5 2 5 4 1 2 3 1
*/