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
		 vector<nagai>w(n);
		 nagai ans=0;
		 for(int i=0;i<n;++i) 
			 cin >> w[i], ans += w[i];
		 vector<int>deg(n);
		 for(int i=0;i<n-1;++i) {
			  int u, v;
				cin >> u >> v;
				--u, --v;
				++deg[u];
				++deg[v];
		 }
		 vector<int>rofl;
		 for(int i=0;i<n;++i) 
			 for(int j=0;j<deg[i]-1;++j) 
				 rofl.push_back(w[i]);
		 sort(rofl.rbegin(),rofl.rend());
		 for(int i=1;i<n;++i)  {
			 cout << ans << ' ';
			 if (i + 1 < n )
			 ans += rofl[i-1];
		 }
		 cout << '\n';
	 }
	 return 0;
}