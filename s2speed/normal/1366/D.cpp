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

const ll maxn = 1e7 + 16 , md = 1e9 + 7 , inf = 2e16;

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

int pr[maxn];
bitset<maxn> gh;

void prime(){
	gh.set();
	for(int i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		pr[i] = i;
		for(ll j = 1ll * i * i ; j < maxn ; j += i){
			if(gh[j]){
				pr[j] = i;
				gh[j] = false;
			}
		}
	}
	return;
}

int ans[maxn][2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int a , b = 1 , h;
		cin>>h;
		a = pr[h];
		while(h > 1){
			b *= pr[h];
			h /= pr[h];
		}
		while(b % a == 0) b /= a;
		if(b == 1){
			ans[i][0] = ans[i][1] = -1;
			continue;
		}
		ans[i][0] = a;
		ans[i][1] = b;
	}
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i][0]<<' ';
	}
	cout<<'\n';
	for(int i = 0 ; i < n ; i++){
		cout<<ans[i][1]<<' ';
	}
	cout<<'\n';
	return 0;
}