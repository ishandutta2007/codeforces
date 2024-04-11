#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

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

bool mark[MAX_N];

void solve(){
	int n;
	cin>>n;
	fill(mark , mark + 2 * n + 1 , false);
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		int h;
		cin>>h; h--;
		if(mark[h]) h++;
		if(!mark[h]){
			ans++;
			mark[h] = true;
		}
	}
	cout<<ans<<'\n';
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