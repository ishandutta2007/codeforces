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

string s;
vector<ll> v;

void solve(){
	v.clear();
	ll n , cnt = 0;
	cin>>n>>s;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == 'a'){
			v.push_back(i);
		}
	}
	ll vs = sze(v) , m = inf;
	for(ll i = 1 ; i < vs ; i++){
		m = min(m , v[i] - v[i - 1]);
	}
	if(m >= 4){
		cout<<"-1\n";
		return;
	}
	if(m == 1){
		cout<<"2\n";
		return;
	}
	if(m == 2){
		cout<<"3\n";
		return;
	}
	for(ll i = 0 ; i < vs - 1 ; i++){
		if(v[i + 1] - v[i] != 3) continue;
		ll cnt[] = {0 , 0} , j = v[i];
		cnt[s[j + 1] - 'b']++; cnt[s[j + 2] - 'b']++;
		if(cnt[0] == 1){
			cout<<"4\n";
			return;
		}
	}
	for(ll i = 0 ; i < vs - 2 ; i++){
		if(!(v[i + 2] - v[i + 1] == v[i + 1] - v[i] && v[i + 1] - v[i] == 3)) continue;
		ll j = v[i];
		if(s[j + 1] != s[j + 4]){
			cout<<"7\n";
			return;
		}
	}
	cout<<"-1\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}