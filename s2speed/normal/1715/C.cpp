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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll cur = n * (n + 1) / 2;
	for(ll i = 1 ; i < n ; i++){
		if(a[i] != a[i - 1]){
			cur += i * (n - i);
		}
	}
	for(ll e = 0 ; e < q ; e++){
		ll i , x;
		cin>>i>>x; i--;
		if(i){
			if(a[i] != a[i - 1]){
				cur -= i * (n - i);
			}
			if(x != a[i - 1]){
				cur += i * (n - i);
			}
		}
		if(i < n - 1){
			if(a[i] != a[i + 1]){
				cur -= (i + 1) * (n - i - 1);
			}
			if(x != a[i + 1]){
				cur += (i + 1) * (n - i - 1);
			}
		}
		a[i] = x;
		cout<<cur<<'\n';
	}
	return 0;
}