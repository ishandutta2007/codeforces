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
		 vector<int>a(n),b(n),c(n);
		 for(auto&x:a)cin >>x;
		 for(auto&x:b)cin >> x;
		 for(auto&x:c)cin >> x;
		 vector<int>p(n);
		 p[0] = a[0];
		 for(int i=1;i<n;++i) {
			 p[i] = a[i];
			 if (p[i] == p[i-1] || i == n-1&&p[i] == p[0]){ 
				 p[i]=b[i];
				 if (p[i] == p[i-1] || i == n-1&&p[i] == p[0]) p[i]=c[i];
			 }
		 }
		 for(int i=0;i<n;++i)
			 cout << p[i] << ' ';
		 cout << '\n';
	 }

	 return 0;
}