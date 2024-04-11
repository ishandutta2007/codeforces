#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 3e6 + 20 , md = 1e9 + 7;
// check problem statement

ll cnt[MAXN] , cnz[MAXN] , cnp[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(cnt , 0 , sizeof(cnt));
	memset(cnz , 0 , sizeof(cnz));
	ll sum , ans , n , q;
	cin>>n; sum = 1ll * n * (n - 1);
	for(int i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		cnt[h]++;
	}
	for(int i = 1 ; i < MAXN ; i++){
		int lm = (MAXN - 1) / i;
		for(int j = 1 ; j <= lm ; j++){
			ll h = 1ll * cnt[i] * cnt[j] - (i == j) * cnt[i];
			cnz[i * j] += h;
		}
	}
	partial_sum(cnz , cnz + MAXN - 1 , cnp);
	cin>>q;
	while(q--){
		ll p;
		cin>>p;
		ans = sum;
		ans -= cnp[p - 1];
		cout<<ans<<'\n';
	}
	return 0;
}

/*

*/