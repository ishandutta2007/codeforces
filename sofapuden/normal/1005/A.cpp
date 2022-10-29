#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;cin >> n;
	int last = 1;
	vector<int> v;
	for(int i = 0, tmp; i < n; ++i){
		cin >> tmp;
		if(tmp == 1 && i != 0){
			v.push_back(last);
		}
		last = tmp;
	}
	v.push_back(last);
	cout << v.size() << "\n";
	for(auto c : v){
		cout << c << " ";
	}
	return;
}

int main(){
	solve();
	return 0;	
}