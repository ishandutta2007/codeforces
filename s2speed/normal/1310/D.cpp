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

const ll maxn = 84 , md = 1e9 + 7 , inf = 1e9;

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

int n , k;
int a[maxn][maxn] , dis[maxn][12];
vector<int> v[2];

void cal(){
	memset(dis , 63 , sizeof(dis));
	dis[0][0] = 0;
	for(int q = 0 ; q < k ; q++){
		int h = q & 1 , o = h ^ 1;
		for(auto i : v[h]){
			for(auto j : v[o]){
				dis[j][q + 1] = min(dis[j][q + 1] , dis[i][q] + a[i][j]);
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>a[i][j];
		}
	}
	int lm = 7e3 , ans = inf;
	for(int e = 0 ; e < lm ; e++){
		v[0].clear(); v[1].clear();
		v[0].push_back(0);
		for(int i = 1 ; i < n ; i++){
			v[rng() % 2].push_back(i);
		}
		cal();
		ans = min(ans , dis[0][k]);
	}
	cout<<ans<<'\n';
	return 0;
}