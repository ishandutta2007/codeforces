#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int>a(n);
		for(auto&x:a)cin>>x;
		if (find(a.begin(),a.end(),k) == a.end()) {
			 cout << "no\n";
			 continue;
		}
		bool ok=false;
		for(int i=0;i<n;++i){
			if (a[i] >= k && i + 1 < n && a[i+1] >= a[i])
				ok = true;
			if (a[i] >= k && i > 0 && a[i-1] >= a[i])
				ok = true;
		}
		for(auto&x:a)
			x = x >= k ? 1 : -1;
		int s = 0;
		int l = 0;
		for(auto x : a) {
			++l;
			s += x;
			if (l > 1 && s > 0)
				ok = true;
			if (s < 0)
				l = 0, s = 0;
		}
		if (ok || n == 1)
			cout << "yes\n";
		else 
			cout << "no\n";
	}
	return 0;
}