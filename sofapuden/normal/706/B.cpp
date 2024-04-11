#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	sort(v.begin(), v.end());
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		int l = 0, r = n-1, ans = -1;
		while(l <= r){
			int mid = (l+r)/2;
			if(v[mid] <= x){
				ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		cout << ans+1 << "\n";
	}
}