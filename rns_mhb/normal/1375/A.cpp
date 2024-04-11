#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t --) {
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		for(int i = 0; i < n; i ++) {
			if(i & 1) cout << -(abs(a[i])) << ' ';
			else cout << abs(a[i]) << ' ';
		}
		cout << endl;
	}
}