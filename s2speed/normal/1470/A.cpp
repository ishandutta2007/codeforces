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
struct piii {
	int first , second , third;
};

const ll MAX_N = 3e5 + 20 , md = 1e9 + 7;
 
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

vector<int> k;
int c[MAX_N];

void solve(){
	k.clear();
	int n , m , x = 0;
	cin>>n>>m;
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		int h;
		cin>>h; h--;
		k.push_back(h);
	}
	for(int i = 0 ; i < m ; i++){
		cin>>c[i];
	}
	sort(k.begin() , k.end() , greater<ll>());
	for(int i = 0 ; i < n ; i++){
		if(x >= k[i]){
			ans += c[k[i]];
		} else {
			ans += c[x++];
		}
	}
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