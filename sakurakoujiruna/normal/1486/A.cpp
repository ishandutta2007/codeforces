#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		
		bool f = 1;
		ll last = 0;
		for(int i = 0; i < n; i ++) {
			ll x; cin >> x;
			x += last;
			if(x < i)
				f = 0;
			else 
				last = x - i;
		}
		
		cout << (f ? "Yes" : "No") << '\n';
	}
}