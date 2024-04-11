#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool mark[MAX_N];
	int n , a[MAX_N];
	string s;
	cin>>n>>s;
	for(int i = 0 ; i < n ; i++){
		mark[i] = false;
		int h;
		cin>>h;
		if(s[i] == '<'){
			a[i] = i - h;
		} else {
			a[i] = i + h;
		}
	}
	int x = 0;
	while(x >= 0 && x < n){
		if(mark[x]){
			cout<<"INFINITE\n";
			return 0;
		}
		mark[x] = true;
		x = a[x];
	}
	cout<<"FINITE\n";
	return 0;
}