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

ll a[maxn] , ls[maxn] , cnt[maxn] , f[maxn] , ps[maxn];

void solve(){
	ll n;
	cin>>n;
	fill(ls , ls + n , -1);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	for(ll i = n - 1 ; ~i ; i--){
		if(ls[a[i]] == -1){
			ls[a[i]] = i;
		}
		f[i] = ls[a[i]];
	}
	ps[0] = f[0]; cnt[0] = (f[0] == 0);
	for(ll i = 1 ; i < n ; i++){
		ps[i] = max(ps[i - 1] , f[i]);
		cnt[i] = cnt[i - 1] + (f[i] == i);
	}
	ll t = -1;
	for(ll i = n - 2 ; ~i ; i--){
		if(a[i] > a[i + 1]){
			t = i;
			break;
		}
	}
	if(t == -1){
		cout<<"0\n";
		return;
	}
	for(ll i = t ; i < n ; i++){
		if(ps[i] == i){
			cout<<cnt[i]<<'\n';
			return;
		}
	}
	return;
}

/*
1
3
3 3 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();	
	return 0;
}