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

const ll MAXN = 1e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll h[MAXN];

void solve(){
	ll n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>h[i];
	}
	ll x;
	for(int i = 0 ; i < k ; i++){
		x = -2;
		for(int j = 0 ; j < n - 1 ; j++){
			if(h[j] < h[j + 1]){
				x = j;
				h[j]++;
				break;
			}
		}
		if(x == -2) break;
	}
	cout<<x + 1<<'\n';
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