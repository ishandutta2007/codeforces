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

ll a[MAXN] , l[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , ans = 0 , x = -1 , y = -1;
	cin>>n;
	if(n <= 2){
		cout<<n<<'\n';
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	l[n - 1] = -2; l[n - 2] = -2;
	for(ll i = n - 3 ; i >= 0 ; i--){
		if(a[i + 1] == a[i + 2]){
			l[i] = a[i + 1];
		} else {
			l[i] = l[i + 1];
		}
	}
	for(ll i = 0 ; i < n ; i++){
		if(x != a[i] && y != a[i]){
			if(x == l[i]){
				x = a[i];
			} else if(y == l[i]){
				y = a[i];
			} else {
				x = a[i];
			}
			ans++;
			continue;
		}
		if(x != a[i]){
			x = a[i];
			ans++;
		} else if(y != a[i]){
			y = a[i];
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

/*

*/