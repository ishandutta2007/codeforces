#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , maxm = 63 , maxp = 33e3 , md = 7340033 , inf = 2e18;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
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

bitset<maxm> a[maxn] , ans;
vector<int> v[maxn];
int cnt[maxp] , dp[maxp];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , m , p;
	cin>>n>>m>>p;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(int j = 0 ; j < m ; j++){
			a[i][j] = (s[j] == '1');
			if(a[i][j]) v[i].push_back(j);
		}
	}
	int sna = 0;
	for(int e = 0 ; e < 50 ; e++){
		int i = rng() % n , vs = sze(v[i]);
		memset(cnt , 0 , sizeof(cnt));
		memset(dp , 0 , sizeof(dp));
		for(int j = 0 ; j < n ; j++){
			int mask = 0;
			for(int k = 0 ; k < vs ; k++){
				if(a[j][v[i][k]]) mask += (1 << k);
			}
			cnt[mask]++;
		}
		int lm = (1 << vs);
		for(int mask = 0 ; mask < lm ; mask++){
			for(int smask = mask ; smask ; smask = (smask - 1) & mask){
				dp[smask] += cnt[mask];
			}
		}
		bitset<maxm> tmp;
		for(int mask = 1 ; mask < lm ; mask++){
			if(dp[mask] < (n + 1) / 2) continue;
			tmp.reset();
			int h = 0;
			for(int k = 0 ; k < vs ; k++){
				if(mask & (1 << k)){
					tmp[v[i][k]] = true;
					h++;
				}
			}
			if(h > sna){
				sna = h;
				ans = tmp;
			}
		}
	}
	for(int i = 0 ; i < m ; i++){
		cout<<ans[i];
	}
	cout<<'\n';
	return 0;
}