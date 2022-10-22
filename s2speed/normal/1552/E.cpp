#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
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

ll a[maxn] , lst[202];
bitset<maxn> mark;
pll ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k , q;
	cin>>n>>k; q = (n + k - 2) / (k - 1);
	for(ll i = 0 ; i < n * k ; i++){
		cin>>a[i]; a[i]--;
	}
	ll cur = 0 , cnt = 0;
	while(cnt != n){
		memset(lst , -1 , sizeof(lst));
		ll h = 0 , i;
		for(i = cur ; h < q && cnt < n ; i++){
			if(mark[a[i]]) continue;
			if(lst[a[i]] == -1){
				lst[a[i]] = i;
			} else {
				ans[a[i]] = {lst[a[i]] , i};
				h++; cnt++;
				mark[a[i]] = true;
			}
		}
		cur = i;
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i].first + 1<<' '<<ans[i].second + 1<<'\n';
	}
	return 0;
}