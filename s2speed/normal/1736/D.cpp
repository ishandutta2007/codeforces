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
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll lcm(ll a , ll b){
	ll h = a * b / gcd(a , b);
	return h;
}

string s;
ll a[maxn];
vector<ll> v;

void solve(){
	v.clear();
	ll n;
	cin>>n>>s;
	ll cnt = 0;
	for(ll i = 0 ; i < (n << 1) ; i++){
		a[i] = s[i] ^ '0';
		cnt += a[i];
	}
	if(cnt & 1){
		cout<<"-1\n";
		return;
	}
	ll cur = 0;
	for(ll i = 0 ; i < (n << 1) ; i += 2){
		if(a[i] != a[i + 1]){
			if(a[i] == cur){
				v.push_back(i);
			} else {
				v.push_back(i + 1);
			}
			cur ^= 1;
		}
	}
	cout<<sze(v)<<' ';
	for(auto i : v){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	for(ll i = 1 ; i < (n << 1) ; i += 2) cout<<i<<' ';
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