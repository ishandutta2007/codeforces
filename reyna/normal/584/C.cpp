//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int mark[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n, t; cin >> n >> t; t = n - t;
	vector<char> ans(n);
	string a, b; cin >> a >> b;
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && p != t) {
			p++;
			ans[i] = a[i];	
		} else if (a[i] == b[i]) {
			for (int c = 'a'; c <= 'c'; c++)
				if (c != a[i] && c != b[i])
					ans[i] = c;	
		}
	}
	int x1 = t - p, x2 = t - p;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (x1) {
				x1--;
				ans[i] = a[i];	
			} else if(x2) {
				x2--;
				ans[i] = b[i];	
			} else {
				for (int c = 'a'; c <= 'c'; c++)
					if (c != a[i] && c != b[i])
						ans[i] = c;	
			}
		}
	}
	if (x1 || x2) {
		cout << -1 << endl;
		return 0;	
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
		
		
}