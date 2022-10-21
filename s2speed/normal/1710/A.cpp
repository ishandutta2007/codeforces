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

void solve(){
	ll a , b , n , sum[] = {0 , 0};
	bool f[] = {false , false};
	cin>>a>>b>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		ll t = h / a , q = h / b;
		sum[0] += (t == 1 ? 0 : t); sum[1] += (q == 1 ? 0 : q);
		f[0] |= (t >= 3); f[1] |= (q >= 3);
	}
	if(sum[0] >= b){
		if(f[0] || (b & 1) != 1){
			cout<<"Yes\n";
			return;
		}
	}
	if(sum[1] >= a){
		if(f[1] || (a & 1) != 1){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}