#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m; cin >> n >> m;
	vector<int> v(n); for(auto & x : v)cin >> x;
	vector<int> k(n-m+1);
	int cu = 0;
	for(int i = 0; i < m; ++i){
		cu+=v[i];
	}
	k[0] = cu;
	for(int i = m; i < n; ++i){
		cu-=v[i-m];
		cu+=v[i];
		k[i-m+1] = cu;
	}
	int mn = INT_MAX;
	int ind = 0;
	for(int i = 0; i < n-m+1; ++i){
		if(mn > k[i]){
			ind = i+1;
			mn = k[i];
		}
	}
	cout << ind << "\n";
}