#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e18;

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

bitset<maxn> gh;
vector<int> pr[maxn];

void prime(){
	gh.set();
	for(int i = 2 ; i < maxn ; i++){
		if(gh[i]){
			for(int j = i ; j < maxn ; j += i){
				gh[j] = false;
				pr[j].push_back(i);
			}
		}
	}
	return;
}

int a[maxn] , b[maxn] , c[maxn] , l[maxn];
vector<int> v[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	prime();
	memset(l , 0 , sizeof(l));
	memset(b , 0 , sizeof(b));
	int n , q , sq; 
	cin>>n>>q; sq = sqrt(n);
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
		for(auto j : pr[a[i]]){
			b[i] = max(b[i] , l[j]);
			l[j] = i;
		}
		c[i] = max(c[i - 1] , b[i]);
		v[i] = v[c[i]];
		if(v[i].size() == sq){
			v[i].erase(v[i].begin());
		}
		v[i].push_back(c[i]);
	}
	for(int e = 0 ; e < q ; e++){
		int l , r , ans = 0;
		cin>>l>>r;
		while(true){
			if(v[r][0] >= l){
				ans += v[r].size();
				r = v[r][0];
			} else {
				break;
			}
		}
		int o = lower_bound(all(v[r]) , l) - v[r].begin() - 1;
		ans += v[r].size() - o;
		cout<<ans<<'\n';
	}
	return 0;
}