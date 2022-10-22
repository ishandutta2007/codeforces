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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 2e5 + 15 , md = 1e9 + 7 , inf = 1e18;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k /= 2;
	}
	return res;
}

ll H , M , o[] = {0 , 1 , 5 , -1 , -1 , 2 , -1 , -1 , 8 , -1};

ll rev(ll k){
	ll a = k % 10 , b = k / 10;
	if(o[a] == -1 || o[b] == -1) return inf;
	return o[a] * 10 + o[b];
}

bool check(ll h , ll m){
	if(rev(h) >= M || rev(m) >= H) return false;
	return true;
}

void solve(){
	ll h , m;
	string s , ans;
	cin>>H>>M>>s;
	h = (s[0] - '0') * 10 + (s[1] - '0'); m = (s[3] - '0') * 10 + (s[4] - '0');
	while(true){
		if(check(h , m)){
			ll a = h / 10 , b = h % 10;
			ans += a + '0';
			ans += b + '0';
			a = m / 10; b = m % 10; ans += ':';
			ans += a + '0';
			ans += b + '0';
			cout<<ans<<'\n';
			return;
		}
		m++;
		if(m == M){
			m = 0;
			h++;
			if(h == H){
				h = 0;
			}
		}
	}
	return;
}

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

/*

*/