#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 3e5 + 15 , MAX = 1e6 + 15 , md = 998244353 , inf = 1e15;

vector<ll> d[MAXN] , pr[MAXN] , sf;
bitset<MAXN> gh , sq;

void prime(){
	sq.set(); sq[0] = false; sf.push_back(1);
	gh.set(); gh[0] = false; gh[1] = false;
	for(ll i = 2 ; i < MAXN ; i++){
		if(gh[i]){
			pr[i].push_back(i);
			for(ll j = 2 * i ; j < MAXN ; j += i){
				pr[j].push_back(i);
				gh[j] = false;
			}
			ll h = i * i;
			for(ll j = h ; j < MAXN ; j += h){
				sq[j] = false;
			}
		}
		if(sq[i]){
			sf.push_back(i);
		}
	}
	for(auto i : sf){
		ll ps = pr[i].size() , lm = 1 << ps;
		for(ll j = 0 ; j < lm ; j++){
			ll o = 1 , h = 1;
			for(ll q = 0 ; q < ps ; q++){
				if(o & j){
					h *= pr[i][q];
				}
				o <<= 1;
			}
			d[i].push_back(h);
		}
	}
	return;
}

ll dp[64] , e[64];
bitset<64> mark;
ll a[MAXN] , z[MAXN] , n;

ll mask(ll x){
	fill(dp , dp + 64 , 7); mark.reset();
	memset(e , 0 , sizeof(e));
	ll ps = pr[x].size() , s = (1 << ps) - 1;
	for(ll j = s ; j >= 0 ; j--){
		ll h = 1 , o = 1;
		for(ll q = 0 ; q < ps ; q++){
			if(o & j){
				h *= pr[x][q];
			}
			o <<= 1;
		}
		e[j] += z[h] - 1;
		for(ll sub = j & (j - 1) ; sub != j ; sub = (sub - 1) & j){
			e[sub] -= e[j];
		}
		if(!e[j]) continue;
		ll u = s ^ j;
		for(ll sub = u ; ; sub = (sub - 1) & u){
			mark[sub] = true;
			dp[sub] = 1;
			if(!sub) break;
		}
	}
	for(ll j = 0 ; j <= s ; j++){
		if(mark[j]) continue;
		for(ll sub = j & (j - 1) ; sub > 0 && sub != j ; sub = (sub - 1) & j){
			if(mark[sub]){
				dp[j] = min(dp[j] , dp[j ^ sub] + 1);
			}
		}
	}
	return dp[s];
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(z , 0 , sizeof(z));
	prime();
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] == 1){
			cout<<"1\n";
			return 0;
		}
		for(auto j : pr[a[i]]){
			ll h = j * j;
			while(a[i] % h == 0) a[i] /= j;
		}
		for(auto j : d[a[i]]){
			z[j]++;
		}
	}
	ll ans = 8;
	for(ll i = 0 ; i < n ; i++){
		ans = min(ans , mask(a[i]) + 1);
	}
	cout<<(ans == 8 ? -1 : ans)<<'\n';
	return 0;
}

/*
7
255255 170170 102102 72930 46410 39270 30030
*/