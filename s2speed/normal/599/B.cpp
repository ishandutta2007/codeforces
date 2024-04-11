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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e15;

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

ll a[maxn] , b[maxn] , f[maxn] , cnt[maxn] , c[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(cnt , 0 , sizeof(cnt));
	bool ch = true;
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		cin>>f[i]; f[i]--;
		cnt[f[i]]++; c[f[i]] = i;
	}
	for(ll i = 0 ; i < m ; i++){
		cin>>b[i]; b[i]--;
		if(cnt[b[i]] == 0){
			cout<<"Impossible\n";
			return 0;
		}
		if(cnt[b[i]] > 1) ch = false;
	}
	if(!ch){
		cout<<"Ambiguity\n";
		return 0;
	}
	cout<<"Possible\n";
	for(ll i = 0 ; i < m ; i++){
		cout<<c[b[i]] + 1<<' ';
	}
	cout<<'\n';	
	return 0;
}