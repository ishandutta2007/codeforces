#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		sort(v.begin(),v.end());
		int ans = 0;
		for(int i = 0; i <= 100; ++i){
			int hi = n-1, lo = 0;
			int cur = 0;
			while(hi > lo){
				if(v[hi]+v[lo] == i)cur++, hi--, lo++;
				else if(v[hi]+v[lo] > i)hi--;
				else lo++;
			}
			ans = max(ans,cur);
		}
		cout << ans << "\n";
			
			
	}
	
			
}