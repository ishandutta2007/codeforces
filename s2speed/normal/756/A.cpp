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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll a[maxn] , b[maxn];
bitset<maxn> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , ans = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		cnt++;
		ll h = i;
		while(!mark[h]){
			mark[h] = true;
			h = a[h];
		}
	}
	ans = (cnt > 1) * cnt;
	cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
		cnt += b[i];
	}
	cout<<ans + !(cnt & 1)<<'\n';
	return 0;
}