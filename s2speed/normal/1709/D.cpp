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

ll a[maxn] , rmq[maxn][20] , rb[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	rb[1] = 0;
	ll o = 2;
	for(ll i = 2 ; i < maxn ; i++){
		rb[i] = rb[i - 1];
		if(i == o){
			o <<= 1;
			rb[i]++;
		}
	}
	ll m , n;
	cin>>m>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		rmq[i][0] = a[i];
	}
	for(ll j = 1 ; j < 20 ; j++){
		ll z = 1 << (j - 1);
		if(z >= n) break;
		for(ll i = 0 ; i + z < n ; i++){
			rmq[i][j] = max(rmq[i][j - 1] , rmq[i + z][j - 1]);
		}
		for(ll i = n - z ; i < n ; i++) rmq[i][j] = rmq[i][j - 1];
	}
	ll q;
	cin>>q;
	for(ll e = 0 ; e < q ; e++){
		ll x1 , y1 , x2 , y2 , k;
		cin>>y1>>x1>>y2>>x2>>k; x1--; x2--;
		if(x1 % k != x2 % k || y1 % k != y2 % k){
			cout<<"NO\n";
			continue;
		}
		if(x1 == x2){
			cout<<"YES\n";
			continue;
		}
		ll h = y1 + ((m - y1) / k) * k;
		if(x1 > x2) swap(x1 , x2);
		ll d = x2 - x1;
		ll o = max(rmq[x1][rb[d]] , rmq[x2 - (1 << rb[d])][rb[d]]);
		cout<<(o < h ? "YES\n" : "NO\n");
	}
	return 0;
}