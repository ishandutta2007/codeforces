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

string s;
bitset<maxn> mark;
vector<ll> v[2];

void solve(){
	v[0].clear(); v[1].clear();
	ll a , b , c , d , cnt[] = {0 , 0} , n;
	cin>>a>>b>>c>>d>>s; n = sze(s);
	for(ll i = 0 ; i < n ; i++){
		cnt[s[i] == 'B']++;
		mark[i] = false;
	}
	if(cnt[0] != a + c + d){
		cout<<"NO\n";
		return;
	}
	for(ll i = 0 ; i < n - 1 ; i++){
		mark[i] = (s[i] != s[i + 1]);
	}
	ll r[] = {0 , 0 , 0};
	ll ls = -1;
	for(ll i = 0 ; i < n ; i++){
		if(mark[i] && ls == -1){
			ls = i;
		} else if(!mark[i] && ls != -1){
			ll d = i - ls;
			if(d & 1){
				r[(s[ls] == 'B')] += (d + 1) >> 1;
				v[(s[ls] == 'B')].push_back((d + 1) >> 1);
			} else {
				r[2] += d >> 1;
			}
			ls = -1;
		}
	}
	if(r[0] > c){
		sort(all(v[0]));
		ll h = 0 , o = c , vs = sze(v[0]);
		for(ll e = 0 ; e < vs ; e++){
			ll i = v[0][e];
			c -= i;
			if(c < 0){
				h = vs - e;
				c = 0;
				break;
			}
		}
		r[2] += r[0] - o - h;
	} else {
		c -= r[0];
	}
	if(r[1] > d){
		sort(all(v[1]));
		ll h = 0 , o = d , vs = sze(v[1]);
		for(ll e = 0 ; e < vs ; e++){
			ll i = v[1][e];
			d -= i;
			if(d < 0){
				h = vs - e;
				d = 0;
				break;
			}
		}
		r[2] += r[1] - o - h;
	} else {
		d -= r[1];
	}
	if(r[2] >= c + d){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return;
}

/*
1
0 0 1 0
AB
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}