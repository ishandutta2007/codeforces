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

vector<ll> a , b;
string s;

void solve(){
	a.clear(); b.clear(); s.clear();
	ll n , m , k;
	cin>>n>>m>>k;
	for(ll i = 0 ; i < n ; i++){
		char c;
		cin>>c;
		a.push_back(c - 'a');
	}
	for(ll i = 0 ; i < m ; i++){
		char c;
		cin>>c;
		b.push_back(c - 'a');
	}
	sort(all(a)); sort(all(b));
	ll x = 0 , y = 0 , cnt = 0 , f = -1;
	for(ll i = 0 ; x < n && y < m ; i++){
		if(cnt == k){
			if(f == 0){
				s += b[y++] + 'a';
			} else {
				s += a[x++] + 'a';
			}
			f ^= 1;
			cnt = 1;
			continue;
		}
		if(a[x] < b[y]){
			s += a[x++] + 'a';
			if(f == 0){
				cnt++;
			} else {
				cnt = 1;
				f = 0;
			}
		} else {
			s += b[y++] + 'a';
			if(f == 1){
				cnt++;
			} else {
				cnt = 1;
				f = 1;
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