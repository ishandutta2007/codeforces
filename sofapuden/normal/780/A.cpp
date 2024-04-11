#include <bits/stdc++.h>
 
using namespace std;

#define vt vector

typedef long long ll;
 
 
const int maxA = 1e6;
const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	set<int> S;
	int a = 0;
	int c = 0;
	for(int i = 0; i < n*2; ++i){
		int t; cin >> t;
		if(S.count(t))c-=2;
		S.insert(t);
		c++;
		a = max(a,c);
	}
	cout << a;
		
				
}
			
 
signed main(){
	solve();
}