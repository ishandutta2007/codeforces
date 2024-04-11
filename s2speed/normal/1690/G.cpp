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

ll a[maxn] , ps[maxn];
set<pll> s;
vector<pll> del;

void solve(){
	s.clear();
	ll n , q;
	cin>>n>>q>>a[0];
	ps[0] = a[0];
	ll pr = 0;
	for(ll i = 1 ; i < n ; i++){
		cin>>a[i]; ps[i] = min(a[i] , ps[i - 1]);
		if(ps[i] != ps[i - 1]){
			s.insert({pr , ps[pr]});
			pr = i;
		}
	}
	s.insert({pr , a[pr]});
	s.insert({n , -inf});
	for(ll e = 0 ; e < q ; e++){
		ll i , d;
		cin>>i>>d; i--;
		a[i] -= d;
		auto it = s.upper_bound({i , inf});
		it--;
		if((*it).second <= a[i]){
			cout<<sze(s) - 1<<' ';
			continue;
		}
		del.clear();
		it = s.lower_bound({i , -1});
		while(true){
			if((*it).second < a[i]) break;
			del.push_back(*it);
			it++;
		}
		for(auto p : del) s.erase(p);
		s.insert({i , a[i]});
		cout<<sze(s) - 1<<' ';
	}
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