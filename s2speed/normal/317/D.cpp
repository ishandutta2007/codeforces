#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<pii , int> piii;
typedef pair<pll , pll> pllll;

const ll maxn = (1 << 30) + 16 , maxm = 1e5 + 16 , md = 1e9 + 7 , inf = 2e9;

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

//int8_t dp[maxn];
//int f[32] , mark[32];
//
//void pre_compute(){
//	memset(mark , 0 , sizeof(mark));
//	memset(dp , 0 , sizeof(dp));
//	memset(f , 0 , sizeof(f));
//	for(int i = 1 ; i <= 30 ; i++){
//		for(int j = i ; j <= 30 ; j += i){
//			f[i] += (1 << (j - 1));
//		}
//	}
//	int lm = (1 << 30);
//	for(int mask = 1 ; mask < lm ; mask++){
//		for(int i = 1 ; i <= 30 ; i++){
//			int h = mask & f[i];
//			if(!(mask & (1 << (i - 1)))) continue;
//			mark[dp[mask ^ h]] = mask;
//		}
//		while(mark[dp[mask]] == mask) dp[mask]++;
//	}
//	cout<<"int g[] = {";
//	for(int i = 0 ; i <= 30 ; i++){
//		cout<<(int)(dp[(1 << i) - 1]);
//		if(i != 30){
//			cout<<" , ";
//		} else {
//			cout<<"};\n";
//		}
//	}
//	return;
//}

int g[] = {0 , 1 , 2 , 1 , 4 , 3 , 2 , 1 , 5 , 6 , 2 , 1 , 8 , 7 , 5 , 9 , 8 , 7 , 3 , 4 , 7 , 4 , 2 , 1 , 10 , 9 , 3 , 6 , 11 , 12 , 14};
bitset<maxm> mark;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	pre_compute();
	ll n , sq , cnt = 1 , f = 1;
	cin>>n; sq = min(n , 100000ll);
	for(ll i = 2 ; i <= sq ; i++){
		if(mark[i]) continue;
		ll h = i , lg = 0;
		while(h <= n){
			if(h < maxm) mark[h] = true;
			cnt++;
			lg++;
			h *= i;
		}
		f ^= g[lg];
	}
	f ^= ((n - cnt) & 1);
	cout<<(f ? "Vasya\n" : "Petya\n");
	return 0;
}