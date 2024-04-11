#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")
#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
#define F first
#define S second
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

ll a[maxn] , dp[maxn];
vector<ll> mn , mx;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dp[0] = 0;
	ll f = a[0] , g = -a[0];
	for(ll i = 1 ; i < n ; i++){
		while(!mn.empty()){
			ll j = mn.back();
			if(a[j] < a[i]){
				break;
			}
			mn.pop_back();
		}
		while(!mx.empty()){
			ll j = mx.back();
			if(a[j] > a[i]){
				break;
			}
			mx.pop_back();
		}
		mn.push_back(i);
		g = max(g , dp[i - 1] - a[i]);
		mx.push_back(i);
		f = max(f , dp[i - 1] + a[i]);
		dp[i] = max(f - a[i] , g + a[i]);
	}
	cout<<dp[n - 1]<<'\n';
	return 0;
}