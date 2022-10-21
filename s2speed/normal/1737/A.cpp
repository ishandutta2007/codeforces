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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

string s , h;
ll cnt[27];

void solve(){
	h.clear();
	memset(cnt , 0 , sizeof(cnt));
	ll n , k , q;
	cin>>n>>k>>s; q = n / k;
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] - 'a']++;
	}
	for(ll i = 0 ; i < k ; i++){
		bool f = false;
		for(ll j = 0 ; j < q ; j++){
			if(cnt[j] == 0){
				h += 'a' + j;
				f = true;
				break;
			}
			cnt[j]--;
		}
		if(!f) h += 'a' + q;
	}
	cout<<h<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}