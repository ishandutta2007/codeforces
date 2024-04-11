#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, q; cin >> n >> q;
	vector<int> v(n); for(auto &x : v) cin >> x;
	int an = accumulate(v.begin(),v.end(),0);
	while(q--){
		int a; cin >> a;
		if(a == 1){
			int x; cin >> x;
			x--;
			if(v[x])an--;
			else an++;
			v[x]^=1;
		}
		else{
			int x; cin >> x;
			if(an >= x)cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}