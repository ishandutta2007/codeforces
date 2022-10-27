#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int c[1000000 + 10];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){    	
		int n, w;
		cin >> n >> w;
		vector<int> a(n);
		for (int i = 0; i < 19; i ++) c[1<<i] = 0;

		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			c[a[i]] ++;
		} 

		int done = 0, ans = 0;
		while (1) {
			++ ans;
			int rem = w;
			for (int i = 19; i >= 0; i --) {
				while (rem >= (1<<i) && c[1<<i]>=1) {
					rem -= (1<<i); c[1<<i] --; done ++;
				}
			}
			if (done == n) break;
		}
		cout << ans << endl;

	}
}