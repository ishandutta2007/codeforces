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

const ll MAXN = 3e5 + 20 , md = 1e9 + 7 , inf = 2e9 + 1;
// check problem statement

ll n , ans;

void solve(ll l , ll r){
	if(l == r - 1){
		ans = l;
		return;
	}
	ll a , b , c;
	if(l == r - 2){
		cout<<"? "<<l<<endl;
		cin>>a;
		cout<<"? "<<l + 1<<endl;
		cin>>b;
		if(a < b){
			ans = l;
		} else {
			ans = l + 1;
		}
		return;
	}
	ll m = (l + r) / 2;
	cout<<"? "<<m<<endl;
	cin>>b;
	cout<<"? "<<m + 1<<endl;
	cin>>c;
	cout<<"? "<<m - 1<<endl;
	cin>>a;
	if(b < min(a , c)){
		ans = m;
		return;
	}
	if(a < b){
		solve(l , m);
		return;
	}
	solve(m + 1 , r);
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	solve(1 , n + 1);
	cout<<"! "<<ans<<endl;
	return 0;
}

/*

*/