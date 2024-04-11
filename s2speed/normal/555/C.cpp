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

const ll maxn = 1e6 + 17 , md = 1e9 + 7 , inf = 2e16;

set<pll> u , l;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n>>q;
	u.insert({0 , 0}); l.insert({0 , 0});
	for(ll e = 0 ; e < q ; e++){
		ll i , j;
		char c;
		cin>>i>>j>>c;
		if(c == 'U'){
			auto it = u.lower_bound(mp(i , -1));
			if(it == u.end()){
				auto jt = l.lower_bound(mp(j , inf));
				jt--;
				cout<<j - (*jt).first<<'\n';
				u.insert({i , (*jt).first});
				continue;
			}
			if((*it).first == i){
				cout<<"0\n";
				continue;
			}
			auto jt = l.lower_bound(mp(j , inf)); jt--;
			ll o = ((*jt).first > n + 1 - (*it).first ? (*jt).first : -1);
			ll h = max((*it).second , o);
			cout<<j - h<<'\n';
			u.insert({i , h});
		} else {
			auto jt = l.lower_bound(mp(j , -1));
			if(jt == l.end()){
				auto it = u.lower_bound(mp(i , inf));
				it--;
				cout<<i - (*it).first<<'\n';
				l.insert({j , (*it).first});
				continue;
			}
			if((*jt).first == j){
				cout<<"0\n";
				continue;
			}
			auto it = u.lower_bound(mp(i , inf)); it--;
			ll o = ((*it).first > n + 1 - (*jt).first ? (*it).first : -1);
			ll h = max((*jt).second , o);
			cout<<i - h<<'\n';
			l.insert({j , h});
		}
	}
	return 0;
}