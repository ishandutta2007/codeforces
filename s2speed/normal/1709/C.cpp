#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

string s , t;

void solve(){
	ll n , cnt[] = {0 , 0};
	cin>>s; n = sze(s);
	if(n & 1){
		cout<<"NO\n";
		return;
	}
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '?') continue;
		cnt[(s[i] == ')')]++;
	}
	bool u = false;
	ll m = n >> 1;
	if(cnt[0] > m || cnt[1] > m){
		cout<<"NO\n";
		return;
	}
	u = (cnt[0] == m) || (cnt[1] == m);
	t = s;
	ll l , r;
	bool f = false;
	for(ll i = 0 ; i < n ; i++){
		if(t[i] != '?') continue;
		if(cnt[0] < m){
			cnt[0]++;
			if(cnt[0] == m){
				l = i;
				f = true;
			}
			t[i] = '(';
		} else {
			if(f){
				r = i;
				f = false;
			}
			t[i] = ')';
		}
	}
	ll h = 0;
	for(ll i = 0 ; i < n ; i++){
		if(t[i] == '('){
			h++;
		} else {
			h--;
		}
		if(h == -1){
			cout<<"NO\n";
			return;
		}
	}
	if(u){
		cout<<"YES\n";
		return;
	}
	swap(t[l] , t[r]);
	for(ll i = 0 ; i < n ; i++){
		if(t[i] == '('){
			h++;
		} else {
			h--;
		}
		if(h == -1){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}