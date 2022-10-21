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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

vector<vector<char>> v;
ll ps[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(ps , 0 , sizeof(ps));
	ll n , m;
	cin>>n>>m;
	v.resize(n);
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			v[i].push_back(s[j]);
		}
	}
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 1 ; j < m ; j++){
			if(v[i - 1][j] == 'X' && v[i][j - 1] == 'X'){
				ps[j - 1]++;
			}
		}
	}
	for(ll i = 1 ; i < m ; i++){
		ps[i] += ps[i - 1];
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll l , r;
		cin>>l>>r; l--; r--;
		if(ps[r - 1] - (l ? ps[l - 1] : 0ll)){
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}
	return 0;
}