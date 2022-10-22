#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

#define time aeuo

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		 int n, m;
		 cin >> n >> m;
		 vector<int>a(m);
		 for(auto&x : a)
			 cin >> x, --x;
		 sort(a.begin(), a.end());
		 vector<int> segs;
		 for(int i = 0; i < m; ++i) {
			  if (i + 1 < m) {
				  if (a[i + 1] - a[i] - 1 > 0) 
					  segs.push_back(a[i + 1] - a[i] - 1);
			  }
			  else {
				  if (a[0] + n - a[i] > 0) 
					  segs.push_back(a[0] + n - a[i] - 1);
			  }
		 }
		 sort(segs.rbegin(), segs.rend());
		 nagai time = 0;
		 int ans = 0;
		 for(int s : segs) {
			 int ss = max(0LL, s - 2 * time);
			 ans += s - ss;
			 if (ss == 0) 
				 continue;
			 else if (ss == 1) {
				 ++time;
				 continue;
			 }
			 else {
				 ++time;
				 ++ans;
				 ++time;
			 }
		 }
		 cout << ans + m << '\n';
	}
}