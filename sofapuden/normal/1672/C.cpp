#include<bits/stdc++.h>

using namespace std;

void solve(int testID){
	int n; cin >> n;
	vector<int> v;
	int ls = 0;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		if(!(ls^x))v.push_back(i);
		ls^=ls^x;
	}
	if(v.size() <= 1){
		cout << 0 << '\n';
		return;
	}
	cout << max(1,v.back()-v.front()-1) << '\n';
}

int main(){
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}