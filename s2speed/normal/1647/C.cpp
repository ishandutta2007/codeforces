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

const ll maxn = 1e2 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> a[maxn];
string s;
vector<pllll> ans;

void solve(){
	ans.clear();
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		for(ll j = 0 ; j < m ; j++){
			a[i][j] = s[j] ^ '0';
		}
	}
	if(a[0][0]){
		cout<<"-1\n";
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = m - 1 ; j ; j--){
			if(a[i][j]){
				ans.push_back({{i + 1 , j} , {i + 1 , j + 1}});
			}
		}
	}
	for(ll i = n - 1 ; i ; i--){
		if(a[i][0]){
			ans.push_back({{i , 1} , {i + 1 , 1}});
		}
	}
	cout<<sze(ans)<<'\n';
	for(auto p : ans){
		cout<<p.first.first<<' '<<p.first.second<<' '<<p.second.first<<' '<<p.second.second<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}