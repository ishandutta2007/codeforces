#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a , b , c , x = 0 , y = 0 , z = 0;
	cin>>a>>b>>c;
	v.push_back({a , 0}); v.push_back({b , 1}); v.push_back({c , 2});
	sort(all(v));
	a = v[2].first; b = v[1].first; c = v[0].first;
	if((a + b + c) & 1){
		cout<<"Impossible\n";
		return 0;
	}
	if(a > b + c){
		cout<<"Impossible\n";
		return 0;
	}
	ll h = b - c;
	x = h;
	a -= h;
	x += a >> 1;
	z += a >> 1;
	c -= a >> 1;
	y += c;
	a = v[2].second; b = v[1].second; c = v[0].second;
	if(a == 0){
		if(b == 1){
			cout<<x<<' '<<y<<' '<<z<<'\n';
		} else {
			cout<<z<<' '<<y<<' '<<x<<'\n';
		}
	} else if(a == 1){
		if(b == 0){
			cout<<x<<' '<<z<<' '<<y<<'\n';
		} else {
			cout<<z<<' '<<x<<' '<<y<<'\n';
		}
	} else {
		if(b == 0){
			cout<<y<<' '<<z<<' '<<x<<'\n';
		} else {
			cout<<y<<' '<<x<<' '<<z<<'\n';
		}
	}
	return 0;
}