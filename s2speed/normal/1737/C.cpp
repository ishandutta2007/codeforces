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

set<pll> s;

void solve(){
	s.clear();
	ll n , a , b , c , d , e , f , g , h , x , y;
	cin>>n>>a>>b>>c>>d>>e>>f>>g>>h;
	ll cnt = 0;
	cnt += a & 1; cnt += c & 1; cnt += e & 1;
	if(cnt == 2){
		x = 0;
	} else {
		x = 1;
	}
	bool o = true;
	o &= (a == 1 || a == n || b == 1 || b == n);
	o &= (c == 1 || c == n || d == 1 || d == n);
	o &= (e == 1 || e == n || f == 1 || f == n);
	if(o){
		pll ab = {a , b} , cd = {c , d} , ef = {e , f} , p;
		s.insert({1 , 1}); s.insert({1 , n}); s.insert({n , 1}); s.insert({n , n});
		if(s.count(ab)){
			p = ab;
		} else if(s.count(cd)){
			p = cd;
		} else {
			p = ef;
		}
		if(p.first == g || p.second == h){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
		return;
	}
	cnt = 0;
	cnt += b & 1; cnt += d & 1; cnt += f & 1;
	y = 2 - cnt;
	if((g & 1) == x && (h & 1) == y){
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}