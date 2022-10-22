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
struct plll {ll first , second , third;};
struct piii {int first , second , third;};

const ll MAXN = 2e6 + 1 , md = 1e9 + 7 , inf = 5e18;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

int t[MAXN];
int8_t z[MAXN];
vector<int> adj[MAXN];
ll cur = 0 , ans = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , k;
	cin>>n>>k;
	for(int i = 0 ; i <= k ; i++){
		t[i] = tav(i , n);
	}
//	int cnt = 0;
	for(int i = 1 ; i <= k ; i++){
		for(int j = 2 * i ; j <= k ; j += i){
			adj[j].push_back(i);
//			cnt++;
		}
	}
//	cout<<sizeof(adj)<<'\n';
	memset(z , 0 , sizeof(z));
	cur = 1;
	z[1] = 1;
	for(int i = 2 ; i <= k ; i++){
		z[i] = -z[i] - 1;
		for(int j = 2 * i ; j <= k ; j += i){
			z[j] += z[i];
		}
		cur += z[i];
		for(auto j : adj[i]){
			cur -= 1ll * z[j] * t[i / j - 1];
			cur += 1ll * z[j] * t[i / j];
		}
		cur %= md; cur += md; cur %= md;
		ll h = cur ^ i;
		ans += h;
		ans %= md;
	}
	cout<<ans<<'\n';
	return 0;
}

/*
2000000 2000000
*/