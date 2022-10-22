#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;

int a[MAX_N];

int tav(ll n , ll k){
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
	ll n , sum[] = {0 , 0};
	bool h;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		sum[i % 2] += a[i];
	}
	if(sum[0] >= sum[1]){
		h = 0;
	} else {
		h = 1;
	}
	for(int i = 0 ; i < n ; i++){
		if(i % 2 == h){
			cout<<a[i]<<' ';
		} else {
			cout<<"1 ";
		}
	}
	cout<<'\n';
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