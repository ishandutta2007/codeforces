#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		n*=2;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			ans+=(x&1 ? 1 : -1);
		}
		cout << (ans ? "No" : "Yes") << '\n';

	}
}