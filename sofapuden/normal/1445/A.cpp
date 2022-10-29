#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n >> x;
		vector<int> a(n), b(n);
		for(auto &y : a)cin >> y;
		for(auto &y : b)cin >> y;
		sort(a.begin(),a.end());
		sort(b.rbegin(),b.rend());
		bool ok = 0;
		for(int i = 0; i < n; ++i){
			if(a[i]+b[i] > x)ok = 1;
		}
		cout << (ok ? "No" : "Yes") << "\n";
			
	}
}