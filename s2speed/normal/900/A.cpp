#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , sum[] = {0 , 0};
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int x , y;
		cin>>x>>y;
		sum[(x > 0)]++;
	}
	if(sum[0] > 1 && sum[1] > 1){
		cout<<"No\n";
	} else {
		cout<<"Yes\n";
	}
	return 0;
}