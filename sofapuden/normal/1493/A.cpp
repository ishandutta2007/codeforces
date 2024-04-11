#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		vector<int> out;
		int n, k; cin >> n >> k;
		for(int i = k+1; i <= n; ++i)out.push_back(i);
		for(int i = (k+1)/2; i < k; ++i)out.push_back(i);
		cout << out.size() << "\n";
		for(auto x : out) cout << x << " ";
		cout << "\n";
	}
}