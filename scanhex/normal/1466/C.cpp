#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	 cin.tie(0);
	 ios::sync_with_stdio(false);
	 int t;
	 cin >> t;
	 while(t--) {
		 string s;
		 cin >> s;
		 int res=0;
		 vector<int>v;
		 for(auto x : s) 
			 v.push_back(x);
		 int cur=1e6;
		 for(int i=1;i<s.size();++i) {
			 if (v[i] == v[i-1] || i > 1 && v[i] == v[i - 2])
				 v[i] = cur++, ++res;
		 }
		 cout << res << '\n';
	 }
	 return 0;
}