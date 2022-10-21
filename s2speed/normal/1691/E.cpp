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

ll l[maxn] , r[maxn] , t[maxn];
vector<ll> cl[2] , cr[2] , lc , rc;
vector<pll> c[2] , cc[2];

void solve(){
	cl[0].clear(); cl[1].clear();
	cr[0].clear(); cr[1].clear();
	c[0].clear(); c[1].clear();
	cc[0].clear(); cc[1].clear();
	lc.clear(); rc.clear();
	ll n , cnt[] = {0 , 0};
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>t[i]>>l[i]>>r[i];
		cl[t[i]].push_back(l[i]);
		cr[t[i]].push_back(r[i]);
		cnt[t[i]]++;
	}
	ll res = 0;
	sort(all(cl[0])); sort(all(cl[1]));
	sort(all(cr[0])); sort(all(cr[1]));
	for(ll i = 0 ; i < n ; i++){
		ll h = lower_bound(all(cr[t[i] ^ 1]) , l[i]) - cr[t[i] ^ 1].begin();
		h += cnt[t[i] ^ 1] - (lower_bound(all(cl[t[i] ^ 1]) , r[i] + 1) - cl[t[i] ^ 1].begin());
		if(h == cnt[t[i] ^ 1]){
			res++;
		} else {
			cc[t[i]].push_back({l[i] , r[i]});
		}
	}
	sort(all(cc[0])); sort(all(cc[1]));
	ll cs[] = {sze(cc[0]) , sze(cc[1])};
	if(cs[0] == 0){
		cout<<n<<'\n';
		return;
	}
	for(ll t = 0 ; t < 2 ; t++){
		c[t].push_back(cc[t][0]);
		for(ll i = 1 ; i < cs[t] ; i++){
			if(cc[t][i].first == c[t].back().first){
				c[t].pop_back();
				c[t].push_back(cc[t][i]);
				continue;
			}
			if(cc[t][i].second > c[t].back().second){
				c[t].push_back(cc[t][i]);
			}
		}
	}
	cs[0] = sze(c[0]); cs[1] = sze(c[1]);
	res += cs[1];
	for(auto p : c[0]){
		lc.push_back(p.first);
		rc.push_back(p.second);
	}
	ll pr = -1;
	for(auto p : c[1]){
		ll h = lower_bound(all(rc) , p.first) - rc.begin();
		res -= (h < pr);
		pr = lower_bound(all(lc) , p.second + 1) - lc.begin();
	}
	cout<<res<<'\n';
	return;
}

/*
1
3
0 0 1
1 1 2
1 1 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}