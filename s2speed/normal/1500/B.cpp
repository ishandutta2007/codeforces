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

const ll MAXN = 5e5 + 15 , md = 1e9 + 7 , inf = 1e10;

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

ll a[MAXN] , b[MAXN] , ch[MAXN] , w[MAXN] , pos[2 * MAXN][2];

int main(){ // check MAXN
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(ch , -1 , sizeof(ch));
	memset(pos , -1 , sizeof(pos));
	ll n , m , k , cyc , t = 0 , ans;
	cin>>n>>m>>k; cyc = n / gcd(n , m); k--;
	fill(w , w + cyc , m);
	ll x = 0;
	for(ll i = 0 ; i < cyc ; i++){
		ch[x] = i;
		x += m;
		x %= n;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		pos[a[i]][0] = i;
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i]; b[i]--;
		pos[b[i]][1] = i;
	}
	ll lm = 2 * max(n , m);
	for(ll i = 0 ; i < lm ; i++){
		if(pos[i][0] == -1 || pos[i][1] == -1) continue;
		ll h = ((pos[i][0] - pos[i][1]) % n + n) % n;
		if(ch[h] == -1) continue;
		w[ch[h]]--;
	}
	for(ll i = 0 ; i < cyc ; i++){
		t += w[i];
	}
	ans = 1ll * (k / t) * cyc * m;
	k %= t;
	k++;
	for(ll i = 0 ; i < cyc ; i++){
		if(k > w[i]){
			k -= w[i];
			ans += m;
			continue;
		}
		while(true){
			ll f = a[ans % n] , g = b[ans % m];
			if(f != g) k--;
			ans++;
			if(k == 0){
				cout<<ans<<'\n';
				return 0;
			}
		}
	}
	return 0;
}

/*

*/