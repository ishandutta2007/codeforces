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

vector<pii> ans;

void solve(){
	ans.clear();
	int n , x;
	cin>>n; x = n - 1;
	db sq = ceil(sqrt(n));
	bool ch = true;
	while(ch){
		if(sq == 2) ch = false;
		while(x > sq){
			ans.push_back({x , n});
			x--;
		}
		ans.push_back({n , sq});
		ans.push_back({n , sq});
		x--;
		n = sq;
		sq = ceil(sqrt(n));
	}
	cout<<ans.size()<<'\n';
	for(auto i : ans){
		cout<<i.first<<' '<<i.second<<'\n';
	}
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