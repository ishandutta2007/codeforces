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

const ll MAXN = 3e5 + 15 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

void solve(){
	ll n , k;
	cin>>n>>k;
	if(n % 2 == 0){
		ll h = k % n;
		cout<<(h % n == 0 ? n : h)<<'\n';
		return;
	}
	k--;
	ll h = n / 2 , o = h + 1 , q;
	q = (k / h) * o;
	q += k % h; q %= n; q++;
	cout<<q<<'\n';
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