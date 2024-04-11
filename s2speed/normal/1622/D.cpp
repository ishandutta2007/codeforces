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

const ll maxn = 5e3 + 16 , md = 998244353 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll ch[maxn][maxn];
string s;
vector<ll> v;

ll chs(ll n , ll k){
	if(n < 0 || k > n || k < 0) return 0;
	return ch[n][k];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ch , 0 , sizeof(ch));
	ch[0][0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		ch[i][0] = 1;
		for(ll j = 1 ; j <= i ; j++){
			ch[i][j] = ch[i - 1][j - 1] + ch[i - 1][j];
			ch[i][j] -= (ch[i][j] >= md) * md;
		}
	}
	ll n , k , ans = 1;
	cin>>n>>k>>s;
	v.push_back(-1);
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '1') v.push_back(i);
	}
	v.push_back(n);
	ll vs = sze(v);
	for(ll j = 0 ; j + k + 1 < vs && k - j > 0 && j < 2 ; j++){
		ll z = 1 - ((j & 1) << 1) , l = j + k + 1;
		for(ll i = 0 ; i + l < vs ; i++){
			ll h = chs(v[i + k + 1] - v[i + l - k - 1] - 1 , k - j) - 1;
			if(h == -1) continue;
			ans += h * z;
//			cout<<ans<<' ';
		}
		ans %= md; ans += (ans < 0) * md;
//		cout<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}