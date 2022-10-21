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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	return (b == 0 ? a : gcd(b , a % b));
}

ll lcm(ll a , ll b){
	return (__int128_t)1 * a * b / gcd(a , b);
}

ll p[maxn];
string s , t;
bitset<maxn> mark;

void solve(){
	ll n;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		cin>>p[i]; p[i]--;
		mark[i] = false;
	}
	ll res = 1;
	for(ll i = 0 ; i < n ; i++){
		if(mark[i]) continue;
		t.clear();
		ll v = i;
		while(!mark[v]){
			mark[v] = true;
			t += s[v];
			v = p[v];
		}
		ll ts = sze(t), o = ts;
		for(ll k = 1 ; k < ts ; k++){
			if(ts % k != 0) continue;
			bool f = true;
			for(ll j = 0 ; j < ts - k ; j++){
				f &= (t[j] == t[j + k]);
			}
			if(f){
				o = k;
				break;
			}
		}
		res = lcm(res , o);
	}
	cout<<res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}