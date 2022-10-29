#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	for(int i = 0; i < n-1; ++i){
		cout << v[i]+v[i+1] << " ";
	}
	cout << v.back() << "\n";
}