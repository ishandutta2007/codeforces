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

ll a[52] , cnt[52];
string s;

void solve(){
	s.clear();
	memset(cnt , 0 , sizeof(cnt));
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		cnt[min(h , m - 1 - h)]++;
	}
	for(ll i = 0 ; i < m ; i++){
		ll o = m - 1 - i , h = min(i , o);
		if(i == h){
			if(cnt[i] >= 1){
				s += 'A';
			} else {
				s += 'B';
			}
		} else {
			if(cnt[h] >= 2){
				s += 'A';
			} else {
				s += 'B';
			}
		}
	}
	cout<<s<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}