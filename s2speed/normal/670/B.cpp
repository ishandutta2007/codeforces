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
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll a[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<ll> v;
	ll n , k;
	cin>>n>>k; k--;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	if(k == 0){
		cout<<a[0]<<'\n';
		return 0;
	}
	ll h = 0;
	for(ll i = 1 ; i <= n ; i++){
		v.push_back(h);
		h += i;
	}
	ll l = 0 , r = n;
	while(l < r - 1){
		ll m = (l + r) / 2;
		if(v[m] > k){
			r = m;
		} else {
			l = m;
		}
	}
	ll q = k - v[l];
	cout<<a[q]<<'\n';
	return 0;
}

/*

*/