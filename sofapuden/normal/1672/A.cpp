#include<bits/stdc++.h>

using namespace std;

void solve(int testID){
	int n; cin >> n;
	int su = 0;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		su+=x-1;
	}
	cout << (su & 1 ? "errorgorn" : "maomao90") << '\n';
}

int main(){
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}