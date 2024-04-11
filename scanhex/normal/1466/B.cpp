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
		 vector<int>ex(2 * n + 5);
		 for(int x : a)
			 ++ex[x];
		 int res =0;
		 vector<bool>good(2 * n + 6);
		 for(int i=0;i<ex.size();++i) {
			 res += ex[i] > 0 || good[i];
			 if (ex[i] > 1 || good[i] && ex[i] > 0)
				 good[i + 1] = true;
		 }
		 cout << res << '\n';
	 }
	 return 0;
}