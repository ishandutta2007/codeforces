#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		int mx = 0;
		map<int,int> m;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			m[x]++;
			mx = max(m[x],mx);
		}
		int x = 2*mx-n;
		cout << max(n&1,x) << "\n";

	}
}