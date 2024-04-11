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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e8;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

int pr[maxn] , nx[maxn] , x[maxn] , y[maxn] , pi[maxn] , ni[maxn];
vector<pii> v;
map<pii , int> t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>x[i]>>y[i];
		v.push_back({x[i] , y[i]});
		t[{x[i] , y[i]}] = i;
	}
	sort(all(v));
	for(int e = 0 ; e < n ; e++){
		int x = v[e].first , y = v[e].second , i = t[v[e]];
		if(!t.count({x , y - 1})){
			pr[i] = y - 1;
		} else {
			pr[i] = pr[t[{x , y - 1}]];
		}
	}
	v.clear();
	for(int i = 0 ; i < n ; i++){
		v.push_back({x[i] , -y[i]});
	}
	sort(all(v));
	for(int e = 0 ; e < n ; e++){
		int x = v[e].first , y = -v[e].second , i = t[{x , y}];
		if(!t.count({x , y + 1})){
			nx[i] = y + 1;
		} else {
			nx[i] = nx[t[{x , y + 1}]];
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(!t.count({x[i] - 1 , y[i]})){
			pi[i] = -1;
		} else {
			pi[i] = t[{x[i] - 1 , y[i]}];
		}
		if(!t.count({x[i] + 1 , y[i]})){
			ni[i] = -1;
		} else {
			ni[i] = t[{x[i] + 1 , y[i]}];
		}
	}
	for(int i = 0 ; i < n ; i++){
		int h = inf;
		pii ind = {-1 , -1};
		int k = i , j = 0;
		while(k > -1 && j < 320){
			int d = x[i] - x[k] + y[i] - pr[k];
			if(d < h){
				h = d;
				ind = {x[k] , pr[k]};
			}
			d = x[i] - x[k] + nx[k] - y[i];
			if(d < h){
				h = d;
				ind = {x[k] , nx[k]};
			}
			k = pi[k];
			j++;
		}
		if(j < h){
			h = j;
			ind = {x[i] - j , y[i]};
		}
		k = ni[i]; j = 1;
		while(k > -1 && j < 320){
			int d = x[k] - x[i] + y[i] - pr[k];
			if(d < h){
				h = d;
				ind = {x[k] , pr[k]};
			}
			d = x[k] - x[i] + nx[k] - y[i];
			if(d < h){
				h = d;
				ind = {x[k] , nx[k]};
			}
			k = ni[k];
			j++;
		}
		if(j < h){
			h = j;
			ind = {x[i] + j , y[i]};
		}
		cout<<ind.first<<' '<<ind.second<<'\n';
	}
	return 0;
}