#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll maxn = 5e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

string s;
ll dp[maxn][maxn];
vector<ll> ind[26] , v;
ll x[26];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll j = 0 ; j < 26 ; j++) ind[j].push_back(-1);
	ll n , cnt = 0;
	cin>>n>>s; s += '#';
	if(n == 1){
		cout<<"1\n";
		return 0;
	}
	for(ll i = 0 ; i < n ; i++){
		if(s[i] != s[i + 1]){
			ll h = s[i] - 'a';
			ind[h].push_back(cnt++);
			v.push_back(h);
		}
	}
	for(ll i = 0 ; i < n ; i++){
		memset(x , 0 , sizeof(x));
		for(ll j = 0 ; j < cnt ; j++){
			ll h = 0 , k = v[j];
			if(x[k] == 0) h++;
			if(i){
				h += dp[i - 1][j];
			}
			if(j){
				h += dp[i][j - 1];
			}
			if(i && x[k]){
				h -= dp[i - 1][ind[v[j]][x[k]]];
			}
			h %= md; h += (h < 0) * md;
			x[k]++;
			dp[i][j] = h % md;
		}
	}
	ll ans = dp[n - 1][cnt - 1] - dp[n - 2][cnt - 1];
	ans %= md; ans += (ans < 0) * md;
	cout<<ans<<'\n';
	return 0;
}