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

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll g[maxn] , mark[maxn] , ans[maxn];
vector<ll> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(mark , 0 , sizeof(mark));
	memset(g , 0 , sizeof(g));
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		for(auto j : v[i]) mark[j] = i;
		while(mark[g[i]] == i) g[i]++;
		ll f = g[i] , sum = i;
		for(ll j = i - 1 ; j >= 1 && sum + j < maxn ; j--){
			sum += j;
			f ^= g[j];
			v[sum].push_back(f);
			if(!f) ans[sum] = i - j + 1;
		}
	}
	if(!g[n]){
		cout<<"-1\n";
	} else {
		cout<<ans[n]<<'\n';
	}
	return 0;
}