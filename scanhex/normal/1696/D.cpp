#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		 int n;
		 cin >> n;
		 vector<int>a(n);
		 for(auto& x : a)cin >> x;
		 vector<array<int, 3>> stdown; // val, mnd
		 vector<array<int, 3>> stup; // val, mnd
		 for(int i = 0; i < n; ++i) {
			 int x = a[i];
			 int oo = 0x3f3f3f3f;
			 int d = oo;
			 if (x == a[0]) {
				 d = 0;
			 }
			 else {
				 while (stdown.size() && stdown.back()[0] < x) stdown.pop_back();
				 while (stup.size() && stup.back()[0] > x) stup.pop_back();
				 int bck = stdown.size() ? stdown.back()[2] : -1;
				 if (stup.size() && stup.back()[2] >= bck) {
					 int L = -1, R = stup.size() - 1;
					 while (R - L > 1) {
						 int M = (L + R) / 2;
						 if (stup[M][2] >= bck)
							 R = M;
						 else 
							 L = M;
					 }
					 d = min(d, stup[R][1] + 1);
				 }
				 bck = stup.size() ? stup.back()[2] : -1;
				 if (stdown.size() && stdown.back()[2] >= bck) {
					 int L = -1, R = stdown.size() - 1;
					 while (R - L > 1) {
						 int M = (L + R) / 2;
						 if (stdown[M][2] >= bck)
							 R = M;
						 else 
							 L = M;
					 }
					 d = min(d, stdown[R][1] + 1);
				 }
			 }
			 if (x == a.back()) {
				 cout << d << '\n';
			 }
			 else {
				 stdown.push_back({x, d, i});
				 stup.push_back({x, d, i});
			 }
		 }
	}
}