#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int t;
	 cin >> t;
	 while(t--) {
	 int n;
	 cin >> n;
	 vector<int>a(n);
	 for(auto&x:a)cin >> x;
	 set<int>rofl;
	 for(int x:a)
		 for(int y:a)
			 rofl.insert(abs(x-y));
	 cout << (int)rofl.size() - 1 << '\n';
	 }
	 return 0;
}