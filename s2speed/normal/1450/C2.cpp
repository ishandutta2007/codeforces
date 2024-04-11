#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
const int MAX_N = 2e5 + 20;
 
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

vector<string> v;

void solve(){
	ll n , xk , ok , xc[] = {0 , 0 , 0} , oc[] = {0 , 0 , 0} , k = 0;
	v.clear();
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		v.push_back(s);
		for(int j = 0 ; j < n ; j++){
			if(s[j] == 'X'){
				k++;
				xc[(i + j) % 3]++;
			} else if(s[j] == 'O'){
				k++;
				oc[(i + j) % 3]++;
			}
		}
	}
	if(xc[0] + oc[1] <= k / 3){
		xk = 0;
		ok = 1;
	} else if(xc[1] + oc[2] <= k / 3){
		xk = 1;
		ok = 2;
	} else {
		xk = 2;
		ok = 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(v[i][j] == 'X' && (i + j) % 3 == xk){
				v[i][j] = 'O';
			} else if(v[i][j] == 'O' && (i + j) % 3 == ok){
				v[i][j] = 'X';
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<v[i]<<'\n';
	}
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}