#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	sort(v.rbegin(),v.rend());
	int cu = 0;
	int ans = 0;
	for(int i = 1; i < n; ++i){
		for(int l = v[i-1]; l > v[i]; --l){
			cu+=i;
			if(cu > k){
				cu = i;
				ans++;
			}
		}
	}
	ans += (cu != 0);
	cout << ans << '\n';
}