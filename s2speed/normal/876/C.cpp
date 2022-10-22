#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

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

int f(int k){
	int h = k;
	while(k > 0){
		h += k % 10;
		k /= 10;
	}
	return h;
}

vector<int> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i = max(1 , n - 90) ; i < n ; i++){
		if(f(i) == n){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i : ans){
		cout<<i<<' ';
	}
	if(ans.size() > 0) cout<<'\n';
	return 0;
}