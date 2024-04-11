#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto & x : v)cin >> x;
	sort(v.begin(), v.end());
	vector<int> sm;
	for(int i = 0; i < n; ++i){
		bool ok = 0;
		for(int j : sm){
			if(!(v[i]%j))ok = 1;
		}
		if(!ok)sm.push_back(v[i]);
	}
	cout << sm.size() << "\n";
}