#include<bits/stdc++.h>

using namespace std;

int main(){
	int b, k; cin >> b >> k;
	vector<int> v(k);
	for(auto &x : v)cin >> x;
	if(k == 1 && v[0] == 0){
		cout << "even\n";
		return 0;
	}
	if(b&1){
		int su = 0;
		for(auto x : v)su+=x;
		cout << ((su)&1 ? "odd" : "even") << '\n';
	}
	else{
		cout << (v.back() & 1 ? "odd" : "even") << '\n';

	}
}