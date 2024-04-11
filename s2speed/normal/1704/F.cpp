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

const ll maxn = 5e5 + 17 , md = 998244353 , inf = 2e16;

ll g[maxn];
bitset<11> mark;
vector<ll> v;
string s;

void solve(){
	ll n;
	cin>>n>>s;
	ll cnt[] = {0 , 0};
	for(ll i = 0 ; i < n ; i++){
		cnt[(s[i] == 'B')]++;
	}
	if(cnt[0] > cnt[1]){
		cout<<"Alice\n";
		return;
	}
	if(cnt[0] < cnt[1]){
		cout<<"Bob\n";
		return;
	}
	ll cur = 1 , f = 0;
	for(ll i = 1 ; i < n ; i++){
		if(s[i] == s[i - 1]){
			cur--;
			f ^= (cur >= 119 ? g[(cur - 85) % 34 + 85] : g[cur]);
			cur = 1;
			continue;
		}
		cur++;
	}
	cur--;
	f ^= (cur >= 119 ? g[(cur - 85) % 34 + 85] : g[cur]);
	cout<<(f > 0 ? "Alice" : "Bob")<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	g[0] = 0; g[1] = 1;
	for(ll i = 2 ; i < 119 ; i++){
		mark.set();
		mark[g[i - 2]] = false;
		for(ll j = 0 ; j <= i - 3 ; j++){
			ll h = g[j] ^ g[i - 3 - j];
			mark[h] = false;
		}
		g[i] = mark._Find_first();
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}