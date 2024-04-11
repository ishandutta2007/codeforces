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
	int x1, x2;
	for(int i = 0; i < n; ++i){
		if(v[i] == 1)x1 = i;
		if(v[i] == n)x2 = i;
	}
	cout << max(n-min(x1,n-1-x1),n-min(x2,n-1-x2))-1;
		
				
}
			
 
signed main(){
	solve();
}