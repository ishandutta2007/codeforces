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

const ll maxn = 2e5 + 16 , maxa = 2e7 + 16 , maxs = 45e2 , md = 1e9 + 7 , inf = 2e18;

int b[maxa] , cnt[maxa];
bitset<maxs> gh;

void prime(){
	gh.set();
	for(int i = 2 ; i < maxs ; i++){
		if(gh[i]){
			for(int j = i ; j < maxa ; j += i){
				if(j < maxs && j > i) gh[j] = false;
				cnt[j]++;
				while(b[j] % i == 0) b[j] /= i;
			}
		}
	}
	for(int i = 1 ; i < maxa ; i++){
		cnt[i] += (b[i] != 1);
	}
	return;
}

ll c , d , x;

int pr(int g){
	ll l = x + 1ll * d * g , z;
	if(l % c != 0) return 0;
	l /= c;
	if(l % g != 0) return 0;
	z = 1ll * l / g;
	return (1 << cnt[z]);
}

void solve(){
	ll ans = 0;
	cin>>c>>d>>x;
	db sq = sqrt(x);
	for(int i = 1 ; i <= sq ; i++){
		if(x % i == 0){
			ans += pr(i);
			if(i * i != x){
				ans += pr(x / i);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	iota(b , b + maxa , 0);
	prime();
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}