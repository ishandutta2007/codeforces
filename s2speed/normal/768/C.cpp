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

const ll maxn = 1e3 + 36 , md = 1e9 + 7 , inf = 2e16;

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

ll cnt[maxn] , xnt[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , k , x;
	cin>>n>>k>>x;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		cnt[h]++;
	}
	bool ch;
	for(ll j = 0 ; j < k ; j++){
		ch = false;
		memset(xnt , 0 , sizeof(xnt));
		for(ll i = 0 ; i < maxn ; i++){
			if(cnt[i] == 0) continue;
			if(ch){
				cnt[i]--;
				xnt[i]++;
				ch = false;
				i--;
				continue;
			}
			ll h = (cnt[i] + 1) / 2 , o = cnt[i] / 2;
			ch = (h > o);
			xnt[i ^ x] += h;
			xnt[i] += o;
		}
		memcpy(cnt , xnt , sizeof(cnt));
	}
	for(ll i = maxn - 1 ; i >= 0 ; i--){
		if(cnt[i]){
			cout<<i<<' ';
			break;
		}
	}
	for(ll i = 0 ; i < maxn ; i++){
		if(cnt[i]){
			cout<<i<<'\n';
			break;
		}
	}
	return 0;
}