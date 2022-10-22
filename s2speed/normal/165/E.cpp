#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 4.2e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll ch[maxn] , a[maxn] , dp[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ch , -1 , sizeof(ch));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		ch[a[i]] = i;
	}
	ll lm = (1 << 22);
	for(ll i = 0 ; i < lm ; i++){
		dp[i] = ch[i];
	}
	for(ll i = 0 ; i < 22 ; i++){
		for(ll mask = 0 ; mask < lm ; mask++){
			if(dp[mask] == -1 && (mask & (1 << i))){
				dp[mask] = dp[mask ^ (1 << i)];
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		ll f = (lm - 1) ^ a[i];
		cout<<(dp[f] == -1 ? -1 : a[dp[f]])<<' ';
	}
	cout<<'\n';
	return 0;
}