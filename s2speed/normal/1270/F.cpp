#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

vector<ll> v , t;
ll ps[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , sq , ans = 0;
	string s;
	cin>>s; n = sze(s);
	if(n == 1){
		cout<<"0\n";
		return 0;
	}
	sq = min(n , 200ll);
	ps[0] = (s[0] == '1'); if(s[0] == '1') v.push_back(0);
	for(ll i = 1 ; i < n ; i++){
		ps[i] = ps[i - 1] + (s[i] == '1');
		if(s[i] == '1') v.push_back(i);
	}
	for(ll i = 1 ; i < sq ; i++){
		t.clear(); t.push_back(0);
		for(ll j = 1 ; j <= n ; j++){
			t.push_back(j - i * ps[j - 1]);
		}
		sort(all(t));
		ll cnt = 1;
		for(ll j = 1 ; j <= n ; j++){
			if(t[j] != t[j - 1]){
				cnt = 1;
				continue;
			}
			ans += cnt++;
		}
	}
	ll vs = sze(v);
	for(ll i = 1 ; i * sq <= n ; i++){
		for(ll j = i - 1 ; j < vs ; j++){
			ll r = (j == vs - 1 ? n - 1 : v[j + 1] - 1);
			for(ll e = (j == i - 1 ? 0 : v[j - i] + 1) ; e <= v[j - i + 1] ; e++){
				ll l = v[j] , h , o;
				l = max(l , e + sq * i - 1);
				o = (l - e + 1) % i;
				h = l + (i - o) % i;
				if(h > r) continue;
				ans += (r - h + i) / i;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}