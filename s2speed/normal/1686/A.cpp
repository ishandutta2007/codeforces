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
	ll n;
	cin>>n;
	ll sum = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout<<"NO\n";
		return;
	}
	sum /= n;
	for(ll i = 0 ; i < n ; i++){
		if(a[i] == sum){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}