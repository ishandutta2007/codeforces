#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
	   int n; 
	   cin >> n;
	   vector<int>a(n);
	   nagai s = 0;
	   bool ok = true;
	   for(auto& x : a){
		   cin >> x, s += x;
	   }
	   int ptr2 = 0;
	   for(int i = 0; i < n; ++i) {
		   if (a[i] < 0) {ok = false; break;}
		   if (a[i] != 0 && ptr2 < i) { ok = false; break;}
		   while (a[i] > 0) {
			   while (ptr2 < n && a[ptr2] >= 0) ++ptr2;
			   if (ptr2 == n) {
				   ok = false;
				   break;
			   }
			   nagai mn = min(a[i], -a[ptr2]);
			   a[i] -= mn;
			   a[ptr2] += mn;
		   }
	   }
	   if (ok)
		   cout << "YES\n";
	   else
		   cout << "NO\n";
  }
  return 0;
}