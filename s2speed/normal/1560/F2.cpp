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

bitset<10> mark;
ll a[maxn] , ans[maxn];

void solve(){
	string s;
	ll k;
	cin>>s>>k;
	ll sz = sze(s);
	for(ll i = 0 ; i < sz ; i++){
		a[i] = s[i] - '0';
	}
	ans[0] = -1;
	for(ll i = sz - 1 ; i > -1 ; i--){
		mark.reset();
		for(ll j = 0 ; j <= i ; j++){
			mark[a[j]] = true;
		}
		if(mark.count() > k) continue;
		if(mark.count() < k || (i == sz - 1 && mark.count() == k)){
			for(ll j = 0 ; j <= i ; j++){
				ans[j] = a[j];
			}
			if(i == sz - 1) break;
			ans[i + 1] = a[i + 1] + 1;
			mark[a[i + 1] + 1] = true;
			if(mark.count() < k) mark[0] = true;
			ll m = mark._Find_first();
			for(ll j = i + 2 ; j < sz ; j++){
				ans[j] = m;
			}
			break;
		} else {
			ll m = -1;
			for(ll j = a[i + 1] + 1 ; j < 10 ; j++){
				if(mark[j]){
					m = j;
					break;
				}
			}
			if(m == -1) continue;
			for(ll j = 0 ; j <= i ; j++){
				ans[j] = a[j];
			}
			ans[i + 1] = m;
			m = mark._Find_first();
			for(ll j = i + 2 ; j < sz ; j++){
				ans[j] = m;
			}
			break;
		}
	}
	if(ans[0] == -1){
		ans[0] = a[0] + 1;
		ll m = (k == 1 ? ans[0] : 0);
		for(ll i = 1 ; i < sz ; i++){
			ans[i] = m;
		}
	}
	for(ll i = 0 ; i < sz ; i++){
		cout<<ans[i];
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}