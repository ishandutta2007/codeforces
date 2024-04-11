#include <bits/stdc++.h>
 
using namespace std;

#define vt vector

typedef long long ll;
 
 
const int maxA = 1e6;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vt<int> v(n);
	for(int &i : v){
		cin >> i;
	}
	int m; cin >> m;
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		if(a != n){
			v[a]+=v[a-1]-b;
		}
		if(a != 1){
			v[a-2]+=b-1;
		}
		v[a-1]=0;
	}
	for(int i : v){
		cout << i << "\n";
	}
		
				
}
			
 
signed main(){
	solve();
}