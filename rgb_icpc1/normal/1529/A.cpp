#include<bits/stdc++.h>
using namespace std;

int a[105];

int main() {
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		int mx = 200;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			mx = min(mx, a[i]);
		}
		int cnt = 0;
		for (int i = 0; i < n; i ++) if (mx == a[i]) cnt ++;
		cout << n - cnt << endl;
	}
}