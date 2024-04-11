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

const ll maxn = 4e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

int ds[maxn];

int dsu(int v){
	return (ds[v] == v ? v : ds[v] = dsu(ds[v]));
}

bool merge(int v , int u){
	v = dsu(v); u = dsu(u);
	ds[u] = v;
	return (u != v);
}

vector<int> v[maxn];
int a[maxn] , cnt[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	ll n , sum = 0 , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		v[a[i]].push_back(i);
		sum += a[i];
		cnt[a[i]]++;
	}
	v[0].push_back(n); cnt[0]++;
	iota(ds , ds + n + 1 , 0);
	int lm = (1 << 18);
	for(int mask = lm - 1 ; mask ; mask--){
		int r , u;
		for(int sub = mask ; sub > (mask >> 1) ; sub = (sub - 1) & mask){
			r = mask - sub; u = sub;
			if(!cnt[r] || !cnt[u]) continue;
			for(int j = 1 ; j < cnt[r] ; j++){
				ans += merge(v[r][j] , v[r][j - 1]) * mask;
			}
			for(int j = 1 ; j < cnt[u] ; j++){
				ans += merge(v[u][j] , v[u][j - 1]) * mask;
			}
			ans += merge(v[r][0] , v[u][0]) * mask;
			cnt[r] = cnt[u] = 1;
		}	
	}
	cout<<ans - sum<<'\n';
	return 0;
}