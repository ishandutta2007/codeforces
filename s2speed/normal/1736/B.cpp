#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	ll h = a * b / gcd(a , b);
	return h;
}

ll a[maxn] , b[maxn];

void solve(){
	ll n;
	cin>>n;
	fill(b , b + n + 1 , 1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		b[i] = lcm(b[i] , a[i]); b[i + 1] = lcm(b[i + 1] , a[i]);
	}
	for(ll i = 0 ; i < n ; i++){
		if(gcd(b[i] , b[i + 1]) != a[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}