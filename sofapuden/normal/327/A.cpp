#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v) cin >> x;
	int ans = accumulate(v.begin(),v.end(),0);
	int mx = -1, cu = 0;
	for(int i = 0; i < n; ++i){
		if(v[i] == 0){
			cu++;
		}
		else{
			cu--;
		}
		mx = max(mx,cu);
		if(cu < 0)cu = 0;
	}
	cout << ans+mx << "\n";
}