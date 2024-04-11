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

ll t[52] , ans = 0;

void cnt(ll n , ll h){
	if(n == 1){
		t[h] = n;
		return;
	}
	cnt(n / 2 , h + 1);
	t[h] = 1 + 2 * t[h + 1];
	return;
}

void cal(ll n , ll l , ll r , ll h){
	if(l == r) return;
	if(n == 1){
		ans++;
		return;
	}
	ll o = t[h + 1];
	if(o >= l && o < r){
		ans += n & 1;
		cal(n / 2 , l , o , h + 1);
		cal(n / 2 , 0 , r - o - 1 , h + 1);
		return;
	}
	if(o > l){
		cal(n / 2 , l , r , h + 1);
	} else {
		cal(n / 2 , l - o - 1 , r - o - 1 , h + 1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , l = -1 , r;
	cin>>n>>l>>r; l--;
	if(n == 0){
		cout<<"0\n";
		return 0;
	}
	cnt(n , 0);
	cal(n , l , r , 0);
	cout<<ans<<'\n';
	return 0;
}