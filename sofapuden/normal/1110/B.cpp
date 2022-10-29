#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	vector<int> rem;
	for(int i = 0; i < n-1; ++i)rem.push_back(v[i+1]-v[i]);
	sort(rem.begin(),rem.end());
	int ans = k;
	for(int i = 0; i < n-k; ++i)ans+=rem[i];
	cout << ans << '\n';

}