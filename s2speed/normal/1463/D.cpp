#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 4e5 + 20 , md = 1e9 + 7;
 
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

bool b[MAX_N];

void solve(){
	ll n , k = 0 , q = 0 , o = 0 , p = 0;
	cin>>n;
	for(int i = 0 ; i < 2 * n ; i++){
		b[i] = false;
	}
	for(int i = 0 ; i < n ; i++){
		int a;
		cin>>a; a--;
		b[a] = true;
	}
	for(int i = 0 ; i < 2 * n ; i++){
		if(b[i]){
			o++;
		} else {
			p++;
		}
		q = max(q , o - p);
	}
	o = 0; p = 0;
	for(int i = 2 * n - 1 ; i >= 0 ; i--){
		if(b[i]){
			o++;
		} else {
			p++;
		}
		k = max(k , o - p);
	}
	q = n - q;
	cout<<q - k + 1<<'\n';
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