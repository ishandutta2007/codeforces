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

const ll MAXN = 2e5 + 20 , md = 2000000357 , inf = 2e9 + 1;
// check problem statement

ll cnt[4] , c[10][4];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(c , 0 , sizeof(c));
	memset(cnt , 0 , sizeof(cnt));
	c[2][0] = 1;
	c[3][1] = 1;
	c[4][0] = 2; c[4][1] = 1;
	c[5][2] = 1;
	c[6][1] = 1; c[6][2] = 1;
	c[7][3] = 1;
	c[8][0] = 3; c[8][3] = 1;
	c[9][0] = 1; c[9][1] = 2; c[9][3] = 1;
	ll n;
	cin>>n;
	string ans;
	for(ll i = 0 ; i < n ; i++){
		char e;
		ll h;
		cin>>e;
		h = e - '0';
		for(ll j = 0 ; j <= 3 ; j++){
			cnt[j] += c[h][j];
		}
	}
	for(ll i = 0 ; i < cnt[3] ; i++){
		ans += '7';
	}
	for(ll i = 0 ; i < cnt[2] ; i++){
		ans += '5';
	}
	for(ll i = 0 ; i < cnt[1] ; i++){
		ans += '3';
	}
	for(ll i = 0 ; i < cnt[0] ; i++){
		ans += '2';
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/