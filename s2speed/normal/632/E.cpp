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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e14;

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

int dis[maxn];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dis , 63 , sizeof(dis));
	int n , k;
	cin>>n>>k;
	v.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	int vs = sze(v);
	for(int i = 1 ; i < vs ; i++){
		v[i] -= v[0];
	}
	dis[0] = 0;
	for(int i = 0 ; i < maxn ; i++){
		if(dis[i] >= k) continue;
		for(ll j = 1 ; j < vs ; j++){
			if(i + v[j] >= maxn) break;
			if(dis[i + v[j]] > dis[i] + 1){
				dis[i + v[j]] = dis[i] + 1;
			}
		}
	}
	int h = k * v[0];
	for(int i = 0 ; i < maxn ; i++){
		if(dis[i] <= k){
			cout<<i + h<<' ';
		}
	}
	cout<<'\n';
	return 0;
}