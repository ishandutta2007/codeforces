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

ll a[maxn];

void solve(){
	ll n , k , b , s;
	cin>>n>>k>>b>>s;
	ll h = b * k + n * (k - 1);
	if(h < s || b * k > s){
		cout<<"-1\n";
		return;
	}
	a[0] = b * k;
	for(ll i = 1 ; i < n ; i++){
		a[i] = 0;
	}
	ll t = s - b * k;
	for(ll i = 0 ; i < n ; i++){
		if(t <= k - 1){
			a[i] += t;
			break;
		}
		a[i] += k - 1;
		t -= k - 1;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}