#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);for(auto &x : v) cin >> x;
	for(int i = 1; i < n; ++i){
		v[i] += v[i-1];
	}
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		int l = 0, r = n-2, bes = n-1;
		while(l <= r){
			int mid = (l+r)/2;
			if(v[mid] >= x){
				bes = mid;
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		cout << bes+1 << "\n";
	}
}