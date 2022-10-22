#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

void solve(){
	int n , m , h = 0 , ps = 0 , ans = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int u;
		cin>>u;
		ps += u;
		h = max(h , ps);
	}
	ans += h;
	h = 0;
	ps = 0;
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		int u;
		cin>>u;
		ps += u;
		h = max(h , ps);
	}
	ans += h;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}